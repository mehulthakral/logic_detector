
from sklearn.svm import SVC
import pandas as pd
import numpy as np
import pickle as pkl
import os.path

class Model():

    def __init__(self,name="model1/dataset.csv",model_name="model1/model.pkl",num=1) -> None:
        self.model_name=model_name
        if os.path.isfile(model_name): 
            with open(model_name, 'rb') as f:
                self.model = pkl.load(f)

        else:
            self.dataset=pd.read_csv(name,header=None)
            self.dataset.dropna()
            self.num=num
            self.model=None
    
    def prepare_dataset(self):
        X=self.dataset[self.dataset.columns[:-1]]
        y=self.dataset[len(self.dataset.columns)-1]
        return X,y

    def predict(self,vec=[]):
        if self.model==None:

            X,y=self.prepare_dataset()
            self.model=SVC(gamma=0.001, C=100., decision_function_shape='ovo')
            self.model.fit(X,y)
            ans=self.model.predict([vec])[0]
            with open(self.model_name,'wb') as f:
                pkl.dump(self.model,f)
            return ans
        else:
            ans=self.model.predict([vec])[0]
            return ans
