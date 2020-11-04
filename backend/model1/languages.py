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

def get_random_alphanumeric_string(letters_count, digits_count):
    sample_str = ''.join((random.choice(string.ascii_letters) for i in range(letters_count)))
    sample_str += ''.join((random.choice(string.digits) for i in range(digits_count)))
    sample_list = list(sample_str)
    random.shuffle(sample_list)
    final_string = ''.join(sample_list)
    return final_string

def flatten_str(y):
    ans=[]
    for i in y:
        for j in i:
            ans.append(ord(j))
    return ans

def flatten_list(y):
    ans=[]
    for i in y:
        for j in i:
            ans.append(j)
    return ans    

class python:
    def __init__(self,f,nums=5000,a=0,b=11,len_list=6,letters_count=3,digits_count=2) -> None:
        """generates random numbers in the range [a,b]"""
        b+=1
        self.func=f
        self.nums=nums
        self.len_list=len_list
        self.a=a
        self.b=b
        self.letters_count=letters_count
        self.digits_count=digits_count
        self.mappings={
            int:lambda :random.randint(a,b),
            float:lambda : random.randint(a,b)+random.random(),
            bool:lambda : bool(random.randint(0,1)),
            list: lambda : [random.randint(a,b) for i in range(self.len_list)],
            tuple: lambda : tuple([random.randint(a,b) for i in range(self.len_list)]),
            set: lambda : {random.randint(a,b) for i in range(self.len_list)},
            str: lambda : get_random_alphanumeric_string(self.letters_count, self.digits_count),
            List[int]: lambda :[random.randint(a,b) for i in range(self.len_list)],
            Tuple[int]: lambda : tuple([random.randint(a,b) for i in range(self.len_list)]),
            Set[int]: lambda : {random.randint(a,b) for i in range(self.len_list)},
            List[float]: lambda :[random.randint(a,b)+random.random() for i in range(self.len_list)],
            Tuple[float]: lambda :tuple([random.randint(a,b)+random.random() for i in range(self.len_list)]),
            Set[float]: lambda :set([random.randint(a,b)+random.random() for i in range(self.len_list)]),
            List[str]: lambda :[get_random_alphanumeric_string(self.letters_count, self.digits_count) for i in range(self.len_list)],
            Tuple[str]: lambda :tuple([get_random_alphanumeric_string(self.letters_count, self.digits_count) for i in range(self.len_list)]),
            Set[str]: lambda :set([get_random_alphanumeric_string(self.letters_count, self.digits_count) for i in range(self.len_list)]),
            List[List[int]]: lambda : [[random.randint(0,1) for i in range(self.len_list)] for j in range(self.len_list)],
            inspect.Parameter.empty:lambda : random.randint(a,b)+random.random()
        }

        self.add_x={
            int: lambda x,y:list.append(x,y),
            float: lambda x,y:list.append(x,y),
            bool: lambda x,y:list.append(x,y),
            list:  lambda x,y:list.extend(x,y),
            tuple: lambda x,y:list.extend(x,list(y)),
            set: lambda x,y:list.extend(x,list(y)),
            str: lambda x,y:list.extend(x,[ord(i) for i in y]),
            List[int]:  lambda x,y:list.extend(x,y),
            Tuple[int]: lambda x,y:list.extend(x,list(y)),
            Set[int]: lambda x,y:list.extend(x,list(y)),
            List[float]: lambda x,y:list.extend(x,y),
            Tuple[float]: lambda x,y:list.extend(x,list(y)),
            Set[float]: lambda x,y:list.extend(x,list(y)),
            List[str]: lambda x,y:list.extend(x,flatten_str(y)),
            Tuple[str]: lambda x,y:list.extend(x,flatten_str(y)),
            Set[str]: lambda x,y:list.extend(x,flatten_str(y)),
            List[List[int]]: lambda x,y:list.extend(x,flatten_list(y)),
            inspect.Parameter.empty:lambda x,y:list.append(x,y)
        }

        self.add_y={
            int:lambda x,y:list.append(x,y),
            float:lambda x,y:list.append(x,y),
            bool:lambda x,y:list.append(x,y),
            list: lambda x,y:list.append(x,y),
            tuple: lambda x,y:list.append(x,list(y)),
            set: lambda x,y:list.append(x,list(y)),
            str: lambda x,y:list.append(x,[ord(i) for i in y]),
            List[int]: lambda x,y:list.append(x,y),
            Tuple[int]: lambda x,y:list.append(x,y),
            Set[int]: lambda x,y:list.append(x,y),
            List[float]: lambda x,y:list.append(x,y),
            Tuple[float]: lambda x,y:list.append(x,y),
            Set[float]: lambda x,y:list.append(x,y),
            List[str]: lambda x,y:list.append(x,flatten_str(y)),
            Tuple[str]: lambda x,y:list.append(x,flatten_str(y)),
            Set[str]: lambda x,y:list.append(x,flatten_str(y)),
            List[List[int]]: lambda x,y:list.append(x,flatten_list(y)),
            inspect.Parameter.empty:lambda x,y:list.append(x,y)
        }

    def data_gen(self):
        params=inspect.signature(self.func).parameters
        l=[]
        action=[]
        for i in params:
            l.append(self.mappings[params[i].annotation]())
            action.append(self.add_x[params[i].annotation])
        return l,action

    def generate_data(self):

        X=[]
        y=[]
        for _ in range(self.nums):
            l,action=self.data_gen()
            
            X.append([])
            
            for i,j in zip(l,action):
                j(X[-1],i)
            ans=self.func(*l)
            self.add_y[type(ans)](y,ans)

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