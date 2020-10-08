
from sklearn.neighbors import KNeighborsClassifier as KNN
from sklearn.neighbors import DistanceMetric
import pandas as pd
import numpy as np
class Model():

    def __init__(self,name="dataset.csv",num=1) -> None:
        self.dataset=pd.read_csv(name,header=None)
        self.dataset.dropna()
        self.num=num
    
    def prepare_dataset(self):
        X=self.dataset[self.dataset.columns[:-1]]
        y=self.dataset[len(self.dataset.columns)-1]
        return X,y

    def predict(self,vec=[]):
        X,y=self.prepare_dataset()
        print(X,y)
        self.model=KNN(n_neighbors=self.num,metric="manhattan")
        self.model.fit(X,y)
        return self.model.predict([vec])[0]

        
