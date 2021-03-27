from sklearn.preprocessing import PolynomialFeatures
from sklearn.linear_model import LinearRegression
from sklearn.metrics import r2_score
import numpy as np
import time
import inspect
import random
import statistics
import tracemalloc
from math import sqrt
from pebble import concurrent
from scipy.optimize import curve_fit
from sklearn.model_selection import train_test_split
from typing import List, Set, Dict, Tuple, Optional
import cppyy
from cppyy.gbl.std import vector,pair
import warnings
warnings.filterwarnings('ignore')
try:
    import param_gen
except:
    from . import param_gen

np.random.seed(0)
random.seed(0)        

def get_approx_upper_bound(a):
    if a==[]:
        return "1"
    num=a[-1][1]
    return num

def get_degree(a):
    if a==[]:
        return "1"
    num=a[-1][1]
    if num=="1": # in case of "1"
        return 0
    num=num.split("^")
    if len(num)==1: # in case of "n"
        return 1
    deg=num[-1]
    if deg=="n": #in case of "2^n"
        return 7
    return int(deg) #in other cases

def greater_vector(a,b):
    for i in reversed(range(len(a))):
        if (get_degree(a)>get_degree(b)) and (a[i][0]>b[i][0]):
            return True 
    return False 

def get_integral(v):
    integrals = {"1":1000000.0,"log(n)":5565705.518096749,"logn":5565705.518096749,"n":499999999999.99994,"m":499999999999.99994,"n^1":499999999999.99994,"nlog(n)":2891426379524.1875,"nlogn":2891426379524.1875,"n^2":3.333333333333333e+17,"m^2":3.333333333333333e+17,"n^3":2.5e+23,"n^2m":2.5e+23,"n^4":1.9999999999999995e+29,"n^5":1.6666666666666666e+35,"n^6":1.4285714285714284e+41,"n^7":1.25e+47,"nm":3.333333333333333e+17,"2^n":1e+100}
    res = 0
    for i in v:
        res = res + (i[0]*integrals[i[1]])/10**6
    return pow(res,1/10)

def get_metric_val(l,weights):
    # weights=[1,0,0,0]
    return sqrt(weights[0]*pow(l[0],2)+weights[1]*pow(l[1],2)+weights[2]*pow(l[2],2)+weights[3]*pow(l[3],2))

class optimizer:

    def __init__(self,func,approx_upper_bound=None) -> None:
        self.func=func
        self.time_limit=1
        d={"1":10**8,"log(n)":10**7,"logn":10**7,"n":10**6,"m":10**6,"n^1":10**6,"nlog(n)":10**5,"nlogn":10**5,"n^2":10**4,"n^3":1000,"2^n":25,"n!":10,"nm":10**4}
        # d1={"1":1,"log(n)":1,"logn":1,"n":1,"n^1":1,"nlog(n)":2,"nlogn":2,"n^2":2,"n^3":3,"2^n":7,"n!":9,"nm":2}
        self.approx_upper_bound=approx_upper_bound
        if approx_upper_bound in d:
            self.high=d[approx_upper_bound]
            self.min_data=10
            # self.max_degree=d1[approx_upper_bound]
        else:
            self.min_data=10
            self.high=10**6
        self.max_degree=9
        self.criteria=r2_score
        self.criteria_min=-np.inf

    def find_model(self,x,y):
        
        def str_replace(s):
            d={"x0":"n","x1":"m","x2":"k"}
            for i in d:
                s=s.replace(i,d[i])
            s=''.join(s.split())
            return s
        
        def normalize(model):
            coef,desc=model
            ans=[]
            for i in range(len(coef)):
                if coef[i]<0.1:
                    continue
                ans.append([coef[i],str_replace(desc[i])])
            if ans==[]:
                return [[1,"1"]]
            return ans
        
        def find_polynomial_model(x_train,y_train,x_test,y_test,deg,pos=True):
            # Train features
            poly = PolynomialFeatures(degree=deg)
            x_poly_train = poly.fit_transform(x_train)
            
            # Linear regression
            linear = LinearRegression(fit_intercept=True,normalize=True,n_jobs=-1,positive=True)
            linear.fit(x_poly_train, y_train)

            # Compare with test data
            x_poly_test = poly.fit_transform(x_test)
            poly_predict = linear.predict(x_poly_test)
            criteria_num = self.criteria(y_test, poly_predict)
            coef=linear.coef_
            named_features=poly.get_feature_names()
            
            model=[list(coef),list(named_features)]
            return criteria_num,normalize(model)
            
        def find_log_model(x_train,y_train,x_test,y_test):
            if len(x_train[0])>1:
                return self.criteria_min,[[0,"1"],[0,"log(n)"]]
            x_train=np.log2(x_train)
            x_test=np.log2(x_test)
            criteria_num,details=find_polynomial_model(x_train,y_train,x_test,y_test,1)
            if len(details)==1:
                details[0]=[details[0][0],"log(n)"]
            else:
                details[1]=[details[1][0],"log(n)"]
            return criteria_num,details
        
        def find_n_log_model(x_train,y_train,x_test,y_test):
            if len(x_train[0])>1:
                return self.criteria_min,[[0,"1"],[0,"nlog(n)"]]
            x_train=x_train*np.log2(x_train)
            x_test=x_test*np.log2(x_test)
            criteria_num,details=find_polynomial_model(x_train,y_train,x_test,y_test,1)
            if len(details)==1:
                details[0]=[details[0][0],"nlog(n)"]
            else:
                details[1]=[details[1][0],"nlog(n)"]
            return criteria_num,details
        
        
        def find_exp_model(x_train,y_train,x_test,y_test):
            if len(x_train[0])>1:
                return self.criteria_min,[[0,"1"],[0,"2^n"]]
            x_train=x_train.flatten()
            x_test=x_test.flatten()
            def func(x,a,b):
                return a+b*np.power(2,x)
            try:
                coef, pcov = curve_fit(func, x_train, y_train,bounds=((0, 0), (np.inf, np.inf)))
                y_predict=func(x_test, *coef)
                criteria_num = self.criteria(y_test, y_predict)
                return criteria_num,[[coef[0],"1"],[coef[1],"2^n"]]
            except:
                return self.criteria_min,[[0,"1"],[0,"2^n"]]
        
        def func_gen(j):
            return lambda x_train,y_train,x_test,y_test: find_polynomial_model(x_train,y_train,x_test,y_test,j)
        
        x=np.array(x)
        y=np.array(y)
        x_train,x_test,y_train,y_test=train_test_split(x,y,test_size=0.4)
        pipe_line=[func_gen(i) for i in range(2,self.max_degree)]
        pipe_line+=[find_exp_model]
        best_model=find_polynomial_model(x_train,y_train,x_test,y_test,1)
        #print(best_model[0])
        for f in pipe_line:
            model=f(x_train,y_train,x_test,y_test)
            #print(model[0])
            if model[0]>best_model[0]:
                model=list(model)
                best_model=model.copy()
        return best_model[1]
    

    def find_metrics(self,data): #time and memory has been implemented
        def helper(data):
            tracemalloc.start()
            start = time.process_time_ns()
            self.func(*data)
            current, peak = tracemalloc.get_traced_memory()
            end = time.process_time_ns()
            tracemalloc.stop()
            return end-start, peak
        helper = concurrent.process(timeout=self.time_limit)(helper)
        time_data = helper(data)
        try:
            time_res,mem_res = time_data.result()  # blocks until results are ready
            print("Peak Memory:",mem_res)
            return time_res,mem_res
        except Exception as e:
            print(e)
            return None,None
    
    def param_generator(self,num,t,config={}):
        if config==inspect._empty:
            config={}
        if "generator" in config:
            return param_gen.param_generator(t,config)()
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
        
    def is_iterable(self,S):
        try:
            iterator = iter(S)
        except TypeError:
            # not iterable
            return False
        else:
            # iterable
            return True
    
    def perform_variations(self,data):
        def rotate(arr,k,t):
            if t==0:
                #rotate left
                return arr[k:]+arr[:k]
            else:
                return arr[-k:]+arr[:-k]
        if random.randint(0,1)==0:
            return data  
        
        choice=random.randint(1,7)
        
        if type(data) in (list,tuple,vector[int],str,vector[str],vector[float]):
            type_data=type(data)
            if choice==1:
                data=sorted(data)
            elif choice==2:
                data=list(reversed(data))
            elif choice==3:
                k=random.randint(0,len(data))
                t=random.randint(0,1)
                data=rotate(data,k,t)
            elif choice==4:
                data=list(reversed(sorted(data)))
            elif choice==5:
                data=sorted(data)
                k=random.randint(0,len(data))
                t=random.randint(0,1)
                data=rotate(data,k,t)  
            elif choice==6:
                data=list(reversed(sorted(data)))
                k=random.randint(0,len(data))
                t=random.randint(0,1)
                data=rotate(data,k,t) 
            else:
                data=list(reversed(data))
                k=random.randint(0,len(data))
                t=random.randint(0,1)
                data=rotate(data,k,t)     
                            
            if type_data==str:
                return ''.join(data)
            else:
                return type_data(data)
        else:
            return data
    
    def generate_data(self):
        params=param_gen.signature(self.func)
        l=[] #list of parameters
        for k in params:
            config=params[k]
            l.append(config)
        x=[]
        y=[]
        y1=[]
        for i in range(len(l)):
            data=[self.param_generator(random.randint(8,20),l[j].annotation,l[j].default) for j in range(len(l))]
            low=2
            high=self.high
            while low<=high:
                mid=low
                data[i]=self.param_generator(mid,l[i].annotation,l[i].default)
                #data[i]=self.perform_variations(data[i])
                time_taken, mem_taken = self.find_metrics(data)
                if time_taken==None:
                    break
                else:
                    ans=[]
                    for j in data:
                        if self.is_iterable(j):
                            ans.append(len(j))
                        else:
                            ans.append(j)
                    x.append(ans)
                    y.append(time_taken)
                    y1.append(mem_taken)
                    low=low*2
            j=1
            low//=2
            while j<=self.min_data:
                if(low<=2):
                    break
                temp=random.randint(2,low)
                data[i]=self.param_generator(temp,l[i].annotation,l[i].default)
                #data[i]=self.perform_variations(data[i])
                time_taken, mem_taken =self.find_metrics(data)
                if time_taken==None:
                    low=low-int(0.1*low) 
                    continue
                
                ans=[]
                for m in data:
                    if self.is_iterable(m):
                        ans.append(len(m))
                    else:
                        ans.append(m)
                x.append(ans)
                y.append(time_taken)  
                y1.append(mem_taken)
                low=low-int(0.1*low)   
                j+=1       
        return x,y,y1    
    
    def generate_vector(self):
        x,y,y1= self.generate_data()
        time_model=self.find_model(x,y)
        mem_model=self.find_model(x,y1)
        return time_model, mem_model        

if __name__=="__main__":
    def order_const(x:int):
        x=0
        for i in range(10000):
            x+=1
    def order_log_n(arr:list):
        x=10
        low = 0
        high = len(arr) - 1
        mid = 0
    
        while low <= high: 
    
            mid = (high + low) // 2
    
            # Check if x is present at mid 
            if arr[mid] < x: 
                low = mid + 1
    
            # If x is greater, ignore left half 
            elif arr[mid] > x: 
                high = mid - 1
    
            # If x is smaller, ignore right half 
            else: 
                return mid 
    
        # If we reach here, then the element was not present 
        return -1
    
    def order_n_power_1(l:list):
        y=0
        for i in range(2*len(l)):
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
             
    obj=optimizer(order_n_power_1)
    time_vector,mem_vector=obj.generate_vector()
    print(time_vector)
    print(mem_vector)
        