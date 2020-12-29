from matplotlib.colors import Normalize
from sklearn.preprocessing import PolynomialFeatures
from sklearn.linear_model import LinearRegression
from sklearn.metrics import r2_score
import numpy as np
from sklearn.model_selection import GridSearchCV
import time
import inspect
import random
import languages
import math
from pebble import concurrent
np.random.seed(0)
random.seed(10)
class python:

    def __init__(self,func,t=10) -> None:
        self.func=func
        self.time_limit=t
        self.num_per_level=3
        self.level={
            0:1,
            1:10,
            2:100,
            3:1000,
            4:10000,
            5:100000,
        }
    

    def find_model(self,x,y):
        model=None
        prev_poly_r2=0
        for deg in range(1,6):

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
            print(poly_r2)
            if poly_r2<prev_poly_r2 or math.isclose(poly_r2,prev_poly_r2,rel_tol=1e-4):
                return poly_features,poly_reg
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
        helper = concurrent.process(timeout=5)(helper)
        future = helper(data)
        try:
            result = future.result()  # blocks until results are ready
            return result
        except:
            return None
    
    def param_generator(self,l,t,config={}):
        random.randint(1,9)
        if config==inspect._empty:
            config={}
        if t==int:
            return random.randint(1,9)*self.level[l]
        else:
            config["len_list"]=random.randint(1,9)*self.level[l]
            config["upper_count"]=languages.python.default_config["upper_count"]*self.level[l]
            config["lower_count"]=languages.python.default_config["lower_count"]*self.level[l]
            config["digits_count"]=languages.python.default_config["digits_count"]*self.level[l]
            config["special_count"]=languages.python.default_config["special_count"]*self.level[l]
            config.pop("generator",None)
            return languages.python.param_generator(t,config)()
    
    def data_gen(self):
        params=inspect.signature(self.func).parameters
        l=[]
        for k in params:
            config=params[k]
            l.append(config)
        ans=[]
        def helper(i,curr):
            if i>=len(l):
                ans.append(curr.copy())
                return 
            for k in range(len(self.level)):
                helper(i+1,curr+[self.param_generator(k,l[i].annotation,l[i].default)])
        for j in range(self.num_per_level):
            helper(0,[]) 
        return ans
    
    def generate_data(self):
        def criteria(a):
            temp=[]
            for i in a:
                if type(i)==list:
                    temp.insert(0,len(i))
                else:
                    temp.append(i)
            return temp
                    
        X=self.data_gen()
        y=[]
        x=[]
        X.sort(key=criteria)
        for i in range(len(X)):
            curr=X[i]
            temp=self.find_time(curr)
            if temp==None:
                return x,y
            y.append(temp)
            temp=[]
            for j in range(len(curr)):
                if type(curr[j])==list:
                    temp.append(len(curr[j]))
                if type(curr[j])==int:
                    temp.append(curr[j])
            x.append(temp)
        return x,y
    
    def generate_model(self):
        x,y= self.generate_data()
        print(x,y)
        model=self.find_model(x,y)
        return self.find_coef(model)

def f(l:list):
    y=0
    for i in range(len(l)):
        y+=1
    return False
obj=python(f)
print(obj.generate_model())
        