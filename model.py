from keras.models import Sequential
from keras.layers import Dense
from keras.utils import to_categorical
from keras.wrappers.scikit_learn import KerasClassifier
from sklearn.preprocessing import LabelEncoder
import pandas as pd 
import numpy as np

def prepare_targets(y):
    le = LabelEncoder()
    le.fit(y)
    y = le.transform(y)
    d=dict(zip(le.transform(le.classes_),le.classes_))
    return y,d

dataset=pd.read_csv("dataset.csv",header=None)


X=dataset[dataset.columns[:-1]]
X_test=np.array(X.loc[len(X.index)-1])
X=X.drop(len(X.index)-1)
ip_dim=len(X.columns)
y=dataset[len(dataset.columns)-1]



lables=set(y)
y,d=prepare_targets(y) 
y=to_categorical(y)
y_test=np.array(y[-1])
y=y[:-1]
num_classes=len(lables)


model = Sequential()
model.add(Dense(8, input_dim=ip_dim, activation='relu'))
model.add(Dense(num_classes, activation='softmax'))
model.compile(loss='categorical_crossentropy', optimizer='adam', metrics=['accuracy'])


model.fit(X, y, epochs=150, batch_size=10)

def test(model,d,X_test,Y_test):
    l= model.predict(np.array(X_test))
    for j in range(len(l)):
        print("test case",j)
        for i in range(len(l[j])):
            print("\t",d[i],":",l[j][i]) 
        print("\t ACTUAL ANS : ",Y_test)

test(model,d,[X_test],[y_test])
        