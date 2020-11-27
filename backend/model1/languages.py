from numpy.random import seed
seed(0)
import tensorflow as tf
tf.random.set_seed(0)

from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense
import pandas as pd 
import numpy as np
import random
import string
import inspect
from typing import List, Set, Dict, Tuple, Optional



class python:
    default_config={"start":0,"end":11,"len_list":8,"upper_count":3,"lower_count":3,"digits_count":3,"special_count":3 }
    def __init__(self,f,nums=5000) -> None:
        self.func=f
        self.nums=nums
    def param_generator(self,t,config={}):
        if config==inspect._empty:
            config={}
        def get_random_alphanumeric_string(c):
            upper_count=c["upper_count"]
            digits_count=c["digits_count"]
            lower_count=c["lower_count"]
            special_count=c["special_count"]
            sample_str = ''.join((random.choice("ABCDEFGHIJKLMNOPQRSTUVWXYZ") for i in range(upper_count)))
            sample_str += ''.join((random.choice("abcdefghijklmnopqrstuvwxyz") for i in range(lower_count)))
            sample_str += ''.join((random.choice("0123456789") for i in range(digits_count)))
            sample_str += ''.join((random.choice(" *&^%$#@!~`'\",\\|[];:.><?/\t\b\v") for i in range(special_count)))
            sample_list = list(sample_str)
            random.shuffle(sample_list)
            final_string = ''.join(sample_list)
            return final_string
        
        def build_missing_config(c):
            if "start" not in c:
                c["start"]=python.default_config["start"]
            if "end" not in c:
                c["end"]=python.default_config["end"]
            if "len_list" not in c:
                c["len_list"]=python.default_config["len_list"]
            if "upper_count" not in c:
                c["upper_count"]=python.default_config["upper_count"]
            if "lower_count" not in c:
                c["lower_count"]=python.default_config["lower_count"]
            if "digits_count" not in c:
                c["digits_count"]=python.default_config["digits_count"]
            if "special_count" not in c:
                c["special_count"]=python.default_config["special_count"]
            
        if "generator" in config:
            return config["generator"]
        
        build_missing_config(config)
        
        mappings={
            int:lambda :random.randint(config["start"],config["end"]),
            float:lambda : random.randint(config["start"],config["end"])+random.random(),
            bool:lambda : bool(random.randint(0,1)),
            list: lambda : [random.randint(config["start"],config["end"]) for i in range(config["len_list"])],
            tuple: lambda : tuple([random.randint(config["start"],config["end"]) for i in range(config["len_list"])]),
            set: lambda : {random.randint(config["start"],config["end"]) for i in range(config["len_list"])},
            str: lambda : get_random_alphanumeric_string(config),
            List[int]: lambda :[random.randint(config["start"],config["end"]) for i in range(config["len_list"])],
            Tuple[int]: lambda : tuple([random.randint(config["start"],config["end"]) for i in range(config["len_list"])]),
            Set[int]: lambda : {random.randint(config["start"],config["end"]) for i in range(config["len_list"])},
            List[float]: lambda :[random.randint(config["start"],config["end"])+random.random() for i in range(config["len_list"])],
            Tuple[float]: lambda :tuple([random.randint(config["start"],config["end"])+random.random() for i in range(config["len_list"])]),
            Set[float]: lambda :set([random.randint(config["start"],config["end"])+random.random() for i in range(config["len_list"])]),
            List[str]: lambda :[get_random_alphanumeric_string(config) for i in range(config["len_list"])],
            Tuple[str]: lambda :tuple([get_random_alphanumeric_string(config) for i in range(config["len_list"])]),
            Set[str]: lambda :set([get_random_alphanumeric_string(config) for i in range(config["len_list"])]),
            List[List[int]]: lambda : [[random.randint(0,1) for i in range(config["len_list"])] for j in range(config["len_list"])],
            inspect.Parameter.empty:lambda : random.randint(config["start"],config["end"])+random.random()
        }
        
        return mappings[t]
    
    def RIF(self,l):
        def is_iterable(S):
            try:
                iterator = iter(S)
            except TypeError:
                # not iterable
                return False
            else:
                # iterable
                return True

        def flatten(object):
            for item in object:
                if isinstance(item, (list, tuple, set)):
                    yield from flatten(item)
                elif type(item)==str:
                    yield from list(item)
                else:
                    yield item
                    
        if not is_iterable(l):
            l=[l]
            
        l=list(flatten(l))
        
        for i in range(len(l)):
            if type(l[i])==str:
                l[i]=ord(l[i])
        return l
        
    def data_gen(self):
        params=inspect.signature(self.func).parameters
        l=[]
        for i in params:
            l.append(self.param_generator(params[i].annotation,params[i].default)())
        return l

    def generate_data(self):

        X=[]
        y=[]
        for _ in range(self.nums):
            l=self.data_gen()
            
            X.append([])
            
            for i in l:
                X[-1].extend(self.RIF(i))
                
            ans=self.func(*l)
            
            y.append(self.RIF(ans))

        return X,y

    def generate_vector(self):
        seed(0)
        tf.random.set_seed(0)
        X,y=self.generate_data()
        if type(y[0]) in (list,tuple,set):
            op_size=len(y[0])
        else:
            op_size=1
        model = Sequential()
        model.add(Dense(6, input_dim=len(X[0]), activation='relu'))
        model.add(Dense(6, activation='relu'))
        model.add(Dense(op_size))


        # compile the keras model
        model.compile(loss='mean_squared_error', optimizer='adam')

        model.fit(X, y, epochs=15, batch_size=15)

        ans=[]
        for i in model.layers[1:-1]:
            temp=i.get_weights()[0]
            temp=list(temp.flatten())
            ans.extend(temp)

        return ans

class clike:
    def __init__(self,f,nums=1000) -> None:
        self.func=f
        self.nums=nums

    def data_gen(self):
        return []

    def generate_vector(self):
        return []

class java:
    def __init__(self,f,nums=1000) -> None:
        self.func=f
        self.nums=nums

    def data_gen(self):
        return []

    def generate_vector(self):
        return []    

def Vector(f,lang):
    if type(f)==str: #if string is given, then exec it
        d={}
        exec(f,globals(),d)
        f=list(d.values())[0]
    if lang=="python":
        obj=python(f)
    else:
        obj=python(max) #default

    ans=obj.generate_vector()

    return ans 