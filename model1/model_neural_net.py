from keras.models import Sequential
from keras.layers import Dense
from keras.utils import to_categorical
from sklearn.preprocessing import LabelEncoder
import pandas as pd 
import numpy as np
import random
from inspect import *
from keras.models import load_model
import pickle


class Model:
    def __init__(self,name="dataset.csv",test_samples=1) -> None:
        self.dataset=pd.read_csv(name,header=None)
        self.num_test_samples=test_samples
        self.model=None
        self.d=None 
        self.X_test=None
        self.y_test=None

    def prepare_targets(self,y):
        le = LabelEncoder()
        le.fit(y)
        y = le.transform(y)
        #d=dict(zip(le.transform(le.classes_),le.classes_))
        return y,le

    def prepare_dataset(self):
        dataset=self.dataset
        num_test_samples=self.num_test_samples
        X=dataset[dataset.columns[:-1]]
        X_test=np.array(X.loc[len(X.index)-num_test_samples])
        X=X.drop(len(X.index)-1)
        ip_dim=len(X.columns)
        y=dataset[len(dataset.columns)-1]

        lables=set(y)
        y,d=self.prepare_targets(y) 
        y_test=y[-num_test_samples]
        y=to_categorical(y)
        y=y[:-num_test_samples]
        num_classes=len(lables)
        return X,y,X_test,y_test,ip_dim,num_classes,d

    def train(self):
        X,y,X_test,y_test,ip_dim,num_classes,d=self.prepare_dataset()

        model = Sequential()


        model.add(Dense(8, input_dim=ip_dim, activation='relu'))
        model.add(Dense(num_classes, activation='softmax'))


        model.compile(loss='categorical_crossentropy', optimizer='adam', metrics=['accuracy'])


        model.fit(X, y, epochs=250, batch_size=10)
        self.model=model
        self.d=d
        self.X_test=[X_test]
        self.y_test=[y_test]
        

    def test(self):
        d=self.d
        l= self.model.predict(np.array(self.X_test))
        for j in range(len(l)):
            print("test case",j)
            for i in range(len(l[j])):
                print("\t",d.inverse_transform([i])[0],":",l[j][i]) 
            print("\t ACTUAL ANS : ",d.inverse_transform([self.y_test[j]])[0])

    def save(self,name="model.h5",label="label.pkl"):
        if self.model==None:
            self.train()
        self.model.save(name)
        output = open(label, 'wb')
        pickle.dump(self.d, output)
        output.close()


    def load(self):
        try:
            self.model=load_model("model.h5")
        except:
            self.save()
        pkl_file = open('label.pkl', 'rb')
        self.d = pickle.load(pkl_file) 
        pkl_file.close()
    
    def predict(self,vec=[]):
        if self.model==None:
            self.load()
        if vec:
            vec=[vec]
            l= self.model.predict(np.array(vec))
            mapping={}
            for i in range(len(l[0])):
                mapping[self.d.inverse_transform([i])[0]]=l[0][i]
            return mapping
        else:
            return {}





if __name__=="__main__":
    obj=Model()
    obj.train()
    obj.test()
    obj.save()




