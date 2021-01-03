from sklearn.preprocessing import PolynomialFeatures
from sklearn.linear_model import LinearRegression
from sklearn.metrics import r2_score
import numpy as np
import time
import inspect
import random
from pebble import concurrent
import json
try:
    import param_gen
except:
    from . import param_gen

np.random.seed(0)
random.seed(10)

class python:

    def __init__(self,func,approx_upper_bound=None,time_limit=1) -> None:
        self.func=func
        self.time_limit=time_limit
        d={"1":10**8,"logn":10**7,"n":10**6,"n1":10**6,"nlogn":10**5,"n2":10**4,"n3":1000,"2n":25,"n!":10,"mn":10**4}
        d1={"1":1,"logn":1,"n":2,"n1":2,"nlogn":2,"n2":3,"n3":4,"2n":6,"n!":9,"mn":3}
        if approx_upper_bound in d:
            self.high=d[approx_upper_bound]
            self.flag=True
            self.min_data=20
            self.max_degree=d1[approx_upper_bound]
        else:
            self.min_data=5
            self.flag=False
            self.high=10**6
            self.max_degree=9

    def find_model(self,x,y):
        def isclose(a,b,tol=10000):
            a=int(a*tol)
            b=int(b*tol)
            if a==b:
                return True 
            return False
        model=None
        prev_poly_r2=0
        for deg in range(1,self.max_degree):

            # Train features
            poly_features = PolynomialFeatures(degree=deg)
            x_poly_train = poly_features.fit_transform(x)

            # Linear regression
            poly_reg = LinearRegression(fit_intercept=True,normalize=True,n_jobs=-1)
            poly_reg.fit(x_poly_train, y)

            # Compare with test data
            x_poly_test = poly_features.fit_transform(x)
            poly_predict = poly_reg.predict(x_poly_test)
            poly_r2 = r2_score(y, poly_predict)
            if poly_r2<prev_poly_r2 or isclose(prev_poly_r2,poly_r2):
                return model
            model=poly_features,poly_reg
            prev_poly_r2=poly_r2
        return model
        

    def find_coef(self,model):
        ridge = model[1]
        poly= model[0]
        coef=ridge.coef_
        named_features=poly.get_feature_names()
        return coef,named_features

    def find_time(self,data):
        def helper(data):
            start = time.process_time_ns()
            self.func(*data)
            end = time.process_time_ns()
            return end-start 
        helper = concurrent.process(timeout=self.time_limit)(helper)
        future = helper(data)
        try:
            result = future.result()  # blocks until results are ready
            return result
        except:
            return None
    
    def param_generator(self,num,t,config={}):
        if config==inspect._empty:
            config={}
        if t==int:
            return num
        else:
            config["len_list"]=num
            config["upper_count"]=num
            config["lower_count"]=num
            config["digits_count"]=num
            config["special_count"]=num
            config.pop("generator",None)
            return param_gen.param_generator(t,config)()
    
    def generate_data(self):
        def is_iterable(S):
            try:
                iterator = iter(S)
            except TypeError:
                # not iterable
                return False
            else:
                # iterable
                return True
        params=inspect.signature(self.func).parameters #mapping proxy
        l=[] #list of parameters
        for k in params:
            config=params[k]
            l.append(config)
        x=[]
        y=[]
        for i in range(len(l)):
            data=[self.param_generator(random.randint(8,20),l[j].annotation,l[j].default) for j in range(len(l))]
            if not self.flag:
                low=2
                high=self.high
                while low<=high:
                    mid=low+(high-low)//2
                    data[i]=self.param_generator(mid,l[i].annotation,l[i].default)
                    time_taken=self.find_time(data)
                    if time_taken==None:
                        high=mid-1
                    else:
                        ans=[]
                        for j in data:
                            if is_iterable(j):
                                ans.append(len(j))
                            else:
                                ans.append(j)
                        x.append(ans)
                        y.append(time_taken)
                        low=mid+1
            else:
                low=self.high
            j=1
            while j<=self.min_data:
                temp=random.randint(2,low)
                data[i]=self.param_generator(temp,l[i].annotation,l[i].default)
                time_taken=self.find_time(data)
                if time_taken==None:
                    low=low-int(0.1*low) 
                    continue
                
                ans=[]
                for m in data:
                    if is_iterable(m):
                        ans.append(len(m))
                    else:
                        ans.append(m)
                x.append(ans)
                y.append(time_taken)  
                low=low-int(0.1*low)   
                j+=1       
        return x,y    
    
    def generate_model(self):
        x,y= self.generate_data()
        model=self.find_model(x,y)
        return model 
    
    def normalize(self,model):
        coef,desc=self.find_coef(model)
        coef=list(coef)
        desc=list(desc)
        pos=len(coef)
        for i in reversed(range(len(coef))):
            if coef[i]>1:
                pos=i 
                break
        coef=coef[:pos+1]
        desc=desc[:pos+1]
        ans=[[coef[i],desc[i]] for i in range(len(coef))]
        return ans
    
    def generate_time_vector(self):
        return self.normalize(self.generate_model())
    
def parse_dataset(func_label):
    try:
        fobj=open("model1/dataset.json")
    except:
        fobj=open("dataset.json")
    obj=json.loads(fobj.read())
    fobj.close()
    if func_label in obj:
        return obj[func_label]
    return None,None,None

def greater_time_vector(a,b):
    if len(a)>len(b):
        return True 
    elif len(b)>len(a):
        return False 
    else:
        for i in reversed(range(len(a))):
            if a[i][0]>b[i][0]:
                return True 
        return False             

def get_approx_upper_bound(a):
    if a==[]:
        return "1"
    num=a[-1][1]
    num=num.split()
    max_deg=0
    for i in range(len(num)):
        temp=num[i].split("^")
        deg=temp[-1]
        if len(temp)==1:
            if deg=="1":
                max_deg+=0
            else:
                max_deg+=1
        else:
            max_deg+=int(deg)
    if max_deg>=9:
        return "n!"
    if max_deg>=6:
        return "2n"
    if max_deg==1:
        return "n"
    return "n"+str(max_deg)
        

if __name__=="__main__":
    def order_n_power_1(l:list):
        y=0
        for i in range(len(l)):
            y+=1
        return False
    def order_n_log_n(l:list):
        l.sort()
    def order_n_power_2(x:int):
        y=0
        for i in range(x):
            for j in range(x):
                y+=1
    def order_n_power_3(x:int):
        y=0
        for i in range(x):
            for j in range(x):
                for k in range(x):
                    y+=1
    def order_2_power_n(x:int):
        y=0
        for i in range(2**x):
            y+=1
    
    def order_m_n(m:int,n:int):
        temp=0
        for i in range(m):
            for j in range(n):
                temp+=1
             
    obj=python(order_n_power_1,"n")
    time_vector=obj.generate_time_vector()
    print(get_approx_upper_bound(time_vector))
        