from numpy.random import seed
seed(0)
import tensorflow
tensorflow.random.set_seed(0)

from keras.models import Sequential
from keras.layers import Dense
import numpy as np 
import csv
from func import func
import random


def generate(f,nums):
    num_params=3
    X=[]
    y=[]
    for i in range(nums):
        l=[random.random() for i in range(num_params)]
        X.append(l)
        y.append(f(*l))
    return X,y


X,y=generate(func,1000)


model = Sequential()
model.add(Dense(12, input_dim=len(X[0]), activation='relu'))
model.add(Dense(8, activation='relu'))
model.add(Dense(1))


# compile the keras model
model.compile(loss='binary_crossentropy', optimizer='adam')

model.fit(X, y, epochs=150, batch_size=10)

weights=model.get_weights()

ans=[]

for i in weights:
    ans.extend(list(i.flatten()))

ans.append(func.__name__)

print(ans)

with open("dataset.csv","a",newline='') as file:
    writer=csv.writer(file)
    writer.writerow(ans)





