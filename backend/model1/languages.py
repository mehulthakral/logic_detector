from numpy.random import seed
seed(0)
import tensorflow as tf
tf.random.set_seed(0)

from keras.models import Sequential
from keras.layers import Dense
import pandas as pd 
import numpy as np
import random
import inspect

class python:
    len_list=3
    mappings={int:random.random,float:random.random,bool:lambda : random.randint(0,1),list: lambda : [random.randint(0,1) for i in range(python.len_list)],tuple: lambda : [random.randint() for i in range(python.len_list)],set: lambda : [random.random() for i in range(python.len_list)],inspect.Parameter.empty:random.random}
    def __init__(self,f,nums=1000) -> None:
        self.func=f
        self.nums=nums

    def data_gen(self):
        params=inspect.signature(self.func).parameters
        l=[]
        for i in params:
            l.append(python.mappings[params[i].annotation]())
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

        model.fit(X, y, epochs=150, batch_size=5,verbose = 0)

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
        exec(f,{},d)
        f=list(d.values())[0]
    if lang=="python":
        obj=python(f)
    else:
        obj=python(max) #default

    ans=obj.generate_vector()

    return ans 