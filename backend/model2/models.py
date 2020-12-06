import numpy as np
import json
import pickle
import csv
import json

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
    #y_pred = nb.predict(X_test)
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
    knn = KNeighborsClassifier(n_neighbors=1,metric="manhattan")
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
            

print('Splitting between training and test data')
X_final_train=[]
y_final_train=[]
X_final_test=[]
y_final_test=[]
y_pred_knn_final=[]
y_pred_nb_final=[]
y_pred_final=[]

for i in data:
    X_train, X_test, y_train, y_test = train_test_split(data[i][0], data[i][1], test_size=0.3, random_state=1000)
    X_final_train+=X_train
    y_final_train+=y_train
    X_final_test+=X_test
    y_final_test+=y_test
    data[i][0] = X_test
    data[i][1] = y_test


nb = MultinomialNB()
nb.fit(X_final_train, y_final_train)

nb_acc={}
for i in data:
    y_pred_nb = nb.predict(data[i][0])
    y_pred_nb_final+=list(y_pred_nb)
    #nb_acc[i]=precision_score(data[i][1],y_pred_nb, average='weighted')
    nb_acc[i]=accuracy_score(data[i][1],y_pred_nb)

knn = KNeighborsClassifier(n_neighbors=1,metric="manhattan")
knn.fit(X_final_train, y_final_train)

knn_acc={}
for i in data:
    y_pred_knn = knn.predict(data[i][0])
    y_pred_knn_final+=list(y_pred_knn)
    #knn_acc[i]=precision_score(data[i][1],y_pred_knn, average='weighted')
    knn_acc[i]=accuracy_score(data[i][1],y_pred_knn)


tup=[i for i in zip(range(len(y_final_test)),y_pred_nb_final,y_pred_knn_final,y_final_test)]
#tup.sort(key = lambda x: x[1])
#print(tup)

pred_label_nb={}
pred_label_knn={}
label_acc_nb={}
label_acc_knn={}
for i in tup:
    if i[1] not in pred_label_nb:
        pred_label_nb[i[1]]=[]
    pred_label_nb[i[1]].append(i)

    if i[2] not in pred_label_knn:
        pred_label_knn[i[2]]=[]
    pred_label_knn[i[2]].append(i)
#print(pred_label_nb)

for i in pred_label_nb:
    correct=list(filter(lambda x:i in x[3], pred_label_nb[i]))
    #print(correct,pred_label_nb[i])
    label_acc_nb[i]=len(correct)/len(pred_label_nb[i])

for i in pred_label_knn:
    correct=list(filter(lambda x:i in x[3], pred_label_knn[i]))
    #print(correct,pred_label_knn[i])
    label_acc_knn[i]=len(correct)/len(pred_label_knn[i])

#print(label_acc_nb,label_acc_knn)


av_acc={}
for i in data:
    y_pred_knn = knn.predict(data[i][0])
    y_pred_nb = nb.predict(data[i][0])

    y_pred=[]
    for j in range(len(data[i][0])):
        #if nb_acc[y_pred_nb[j]] > knn_acc[y_pred_knn[j]]:
        if label_acc_nb[y_pred_nb[j]] > label_acc_knn[y_pred_knn[j]]:
            y_pred.append(y_pred_nb[j])
        else:
            y_pred.append(y_pred_knn[j])
 
    y_pred_final+=y_pred
    av_acc[i]=accuracy_score(data[i][1], y_pred)
    print(i,"Average Accuracy: ",av_acc[i])
    print(i,"KNN Accuracy: ",knn_acc[i])
    print(i,"NB Accuracy: ",nb_acc[i])


def All_Results(y_test,y_pred):
    result = {
            'accuracy': accuracy_score(y_test, y_pred),
            'f1_weighted': f1_score(y_test, y_pred, average='weighted'),
            'precision_weighted': precision_score(y_test, y_pred, average='weighted'),
            'recall_weighted': recall_score(y_test, y_pred, average='weighted')
            }
    return result

print()
print("Average",All_Results(y_final_test,y_pred_final))
print("KNN",All_Results(y_final_test,y_pred_knn_final))
print("NB",All_Results(y_final_test,y_pred_nb_final))
