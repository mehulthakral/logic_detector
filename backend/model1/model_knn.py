
from sklearn.neighbors import KNeighborsClassifier as KNN
from sklearn.neighbors import DistanceMetric
import pandas as pd
import numpy as np
class Model():

    def __init__(self,name="model1/dataset.csv",num=1) -> None:
        self.dataset=pd.read_csv(name,header=None)
        self.dataset.dropna()
        self.num=num
    
    def prepare_dataset(self):
        X=self.dataset[self.dataset.columns[:-1]]
        y=self.dataset[len(self.dataset.columns)-1]
        return X,y

    def predict(self,vec=[]):
        X,y=self.prepare_dataset()
        self.model=KNN(n_neighbors=self.num,metric="manhattan")
        self.model.fit(X,y)
        # key=self.model.classes_
        # val=list(self.model.predict_proba([vec])[0])
        # d={}
        # k=0
        # for i in key:
        #     d[i]=val[k]
        #     k+=1
        ans=self.model.predict([vec])[0]
        # return d
        return {ans:1}
