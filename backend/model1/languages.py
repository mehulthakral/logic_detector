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

class python:
    def __init__(self,f,nums=1000,a=0,b=5,len_list=3,letters_count=2,digits_count=1) -> None:
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
            list: lambda : [random.randint(a,b) for i in range(len_list)],
            tuple: lambda : tuple([random.randint(a,b) for i in range(len_list)]),
            set: lambda : {random.randint(a,b) for i in range(len_list)},
            str: lambda : get_random_alphanumeric_string(self.letters_count, self.digits_count),
            List[int]: lambda :[random.randint(a,b) for i in range(len_list)],
            Tuple[int]: lambda : tuple([random.randint(a,b) for i in range(len_list)]),
            Set[int]: lambda : {random.randint(a,b) for i in range(len_list)},
            List[float]: lambda :[random.randint(a,b)+random.random() for i in range(len_list)],
            Tuple[float]: lambda :tuple([random.randint(a,b)+random.random() for i in range(len_list)]),
            Set[float]: lambda :set([random.randint(a,b)+random.random() for i in range(len_list)]),
            List[str]: lambda :[get_random_alphanumeric_string(self.letters_count, self.digits_count) for i in range(len_list)],
            Tuple[str]: lambda :tuple([get_random_alphanumeric_string(self.letters_count, self.digits_count) for i in range(len_list)]),
            Set[str]: lambda :set([get_random_alphanumeric_string(self.letters_count, self.digits_count) for i in range(len_list)]),
            inspect.Parameter.empty:lambda : random.randint(a,b)+random.random()
        }

    def data_gen(self):
        params=inspect.signature(self.func).parameters
        l=[]
        for i in params:
            l.append(self.mappings[params[i].annotation]())
        return l

    def generate_data(self):

        X=[]
        y=[]
        for _ in range(self.nums):
            l=self.data_gen()
            
            X.append([])
            
            for j in l:
                if type(j)==list:
                    X[-1].extend(j)
                else:
                    X[-1].append(j)

            y.append(self.func(*l))

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
        model.add(Dense(3, input_dim=len(X[0]), activation='relu'))
        model.add(Dense(6, activation='relu'))
        model.add(Dense(op_size))


        # compile the keras model
        model.compile(loss='mse', optimizer='adam')

        model.fit(X, y, epochs=150, batch_size=5)

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