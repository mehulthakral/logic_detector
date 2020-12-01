import numpy as np
import json
import pickle
import csv

from sklearn.model_selection import train_test_split
from sklearn.naive_bayes import MultinomialNB
from sklearn.neighbors import KNeighborsClassifier
from sklearn.metrics import accuracy_score, f1_score, precision_score, recall_score, roc_auc_score, confusion_matrix, classification_report


def model_NB(X_train, X_test, y_train, y_test):
    print('Declaring NB')
    nb = MultinomialNB()
    print ('Fitting')
    nb.fit(X_train, y_train)

    print ('Predicting values for test data')
    y_pred = nb.predict(X_test)
    print("NB Accuracy: ",nb.score(X_test, y_test))
    # print("F1 Score: ",f1_score(y_test, y_pred))
    # result = {
    #         'accuracy': nb.score(X_test, y_test),
    #         'f1': f1_score(y_test, y_pred),
    #         'f1_weighted': f1_score(y_test, y_pred, average='weighted'),
    #         'precision': precision_score(y_test, y_pred),
    #         'precision_weighted': precision_score(y_test, y_pred, average='weighted'),
    #         'recall': recall_score(y_test, y_pred),
    #         'recall_weighted': recall_score(y_test, y_pred, average='weighted')
    #         }
    # print(result)

    filename = 'naivebayes.sav'
    pickle.dump(nb, open(filename, 'wb'))


def model_KNN(X_train, X_test, y_train, y_test):
    print('Declaring KNN')
    knn = KNeighborsClassifier(n_neighbors=7,metric="manhattan")
    print ('Fitting')
    knn.fit(X_train, y_train)

    print ('Predicting values for test data')
    y_pred = knn.predict(X_test)
    print("KNN Accuracy: ",accuracy_score( y_test,y_pred))
    # print("F1 Score: ",f1_score(y_test, y_pred))
    # result = {
    #         'accuracy': nb.score(X_test, y_test),
    #         'f1': f1_score(y_test, y_pred),
    #         'f1_weighted': f1_score(y_test, y_pred, average='weighted'),
    #         'precision': precision_score(y_test, y_pred),
    #         'precision_weighted': precision_score(y_test, y_pred, average='weighted'),
    #         'recall': recall_score(y_test, y_pred),
    #         'recall_weighted': recall_score(y_test, y_pred, average='weighted')
    #         }
    # print(result)

    filename = 'knn.sav'
    pickle.dump(knn, open(filename, 'wb'))

## WORKING WITH MODELS
tagged_pgm_list = []
#X = []
#y = []
data={}
with open('dataset_encoded.csv') as csvfile:
    reader = csv.reader(csvfile, delimiter=',')

    for r in reader:
        if r != []:
            # print(r,"\n",len(r),"\n\n\n")
            tagged_pgm_list.append(r)
            tag = r[-1]
            #y.append(tag)
            r.remove(tag)
            # print(r)
            r = [float(rr) for rr in r]
            #X.append(r)
            if tag not in data:
                data[tag]=[]
                data[tag].append([])
                data[tag].append([])
            data[tag][0].append(r)
            data[tag][1].append(tag)
            

# print(X,y)
"""
print('Splitting between training and test data')

X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.3, random_state=1000)

model_NB(X_train, X_test, y_train, y_test)
model_KNN(X_train, X_test, y_train, y_test)
"""

print('Splitting between training and test data')
X_final_train=[]
y_final_train=[]

for i in data:
    X_train, X_test, y_train, y_test = train_test_split(data[i][0], data[i][1], test_size=0.3, random_state=1000)
    X_final_train+=X_train
    y_final_train+=y_train
    data[i][0] = X_test
    data[i][1] = y_test

#print(X_final_train,y_final_train)
nb = MultinomialNB()
nb.fit(X_final_train, y_final_train)

for i in data:
    print(i," NB Accuracy: ",nb.score(data[i][0], data[i][1]))

knn = KNeighborsClassifier(n_neighbors=7,metric="manhattan")
knn.fit(X_train, y_train)

for i in data:
    y_pred = knn.predict(data[i][0])
    print(i,"KNN Accuracy: ",accuracy_score(data[i][0], y_pred))