
from sklearn.neighbors import KNeighborsClassifier as KNN
import pandas as pd

class Model():

    def __init__(self,num=1) -> None:
        try:
            self.dataset=pd.read_csv("model1/dataset.csv",header=None)
        except:
            self.dataset=pd.read_csv("dataset.csv",header=None)
        self.num=num
    
    def prepare_dataset(self):
        X=self.dataset[self.dataset.columns[:-1]]
        y=self.dataset[len(self.dataset.columns)-1]
        return X,y

    def predict(self,vec=[]):
        X,y=self.prepare_dataset()
        self.model=KNN(n_neighbors=self.num,metric="manhattan")
        self.model.fit(X,y)
        ans=self.model.predict([vec])[0]
        return ans
