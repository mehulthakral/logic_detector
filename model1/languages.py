from numpy.random import seed
seed(0)
import tensorflow
tensorflow.random.set_seed(0)


from keras.models import Sequential
from keras.layers import Dense
import pandas as pd 
import numpy as np
import random
from inspect import *

class python:
    len_list=3
    mappings={int:random.random,float:random.random,bool:lambda : random.randint(0,1),list: lambda : [random.random() for i in range(python.len_list)],tuple: lambda : [random.random() for i in range(python.len_list)],set: lambda : [random.random() for i in range(python.len_list)],Parameter.empty:random.random}
    def __init__(self,f,nums=1000) -> None:
        self.func=f
        self.nums=nums

    def data_gen(self):
        params=signature(self.func).parameters
        l=[]
        for i in params:
            l.append(python.mappings[params[i].annotation]())
        return l

    def generate_data(self):

        X=[]
        y=[]
        for i in range(self.nums):
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
        tensorflow.random.set_seed(0)
        X,y=self.generate_data()
        

        model = Sequential()
        model.add(Dense(6, input_dim=len(X[0]), activation='relu'))
        model.add(Dense(12, activation='relu'))
        model.add(Dense(1))


        # compile the keras model
        model.compile(loss='mse', optimizer='adam')

        model.fit(X, y, epochs=500, batch_size=10)

        weights=model.get_weights()[2:]

        ans=[]

        for i in weights:
            ans.extend(list(i.flatten()))


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