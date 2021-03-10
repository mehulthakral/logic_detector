from numpy.random import seed
seed(0)
import tensorflow as tf
tf.random.set_seed(0)

from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense
import inspect
from typing import List, Set, Dict, Tuple, Optional
import cppyy
from cppyy.gbl.std import vector,pair
try:
    import param_gen
except:
    from . import param_gen 

class predictor:
    def __init__(self,f,nums=500) -> None:
        self.func=f
        self.nums=nums
    
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
        params=param_gen.signature(self.func)
        l=[]
        for i in params:
            l.append(param_gen.param_generator(params[i].annotation,params[i].default)())
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
        model.add(Dense(20, input_dim=len(X[0]), activation='relu'))
        model.add(Dense(20, activation='relu'))
        model.add(Dense(op_size))

        # compile the keras model
        model.compile(loss='mean_squared_error',optimizer="adam")
        model.fit(X, y, epochs=5, batch_size=50)

        ans=[]
        for i in model.layers[1:-1]:
            temp=i.get_weights()[0]
            temp=list(temp.flatten())
            ans.extend(temp)

        return ans    