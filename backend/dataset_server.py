import os
import random
import importlib.machinery
import model1.predict as mp

# def test():
#     # print(os.listdir('.'))
#     labels = os.listdir('.')
#     labels.remove(os.path.basename(__file__))
#     # print(labels)
#     label = random.choice(labels)
#     # print(label)
#     prgs = os.listdir(label)
#     if '__pycache__' in prgs:
#         prgs.remove('__pycache__')
#     prg = random.choice(prgs)
#     # print(prg)
#     loader = importlib.machinery.SourceFileLoader(label, label+'/'+prg)
#     handle = loader.load_module(label)
#     s = handle.Solution()
#     return getattr(s, label)
#     # return s.label

def test():
    # print(os.listdir('.'))
    labels = os.listdir('dataset_working')
    # labels.remove(os.path.basename(__file__))
    # print(labels)
    label = random.choice(labels)
    # print(label)
    prgs = os.listdir('dataset_working'+'/'+label)
    if '__pycache__' in prgs:
        prgs.remove('__pycache__')
    prg = random.choice(prgs)
    # print(prg)
    loader = importlib.machinery.SourceFileLoader('dataset_working'+'/'+label, 'dataset_working'+'/'+label+'/'+prg)
    handle = loader.load_module('dataset_working'+'/'+label)
    s = handle.Solution()
    return getattr(s, label)
    # return s.label


def evaluate():
    labels = os.listdir('dataset_working')
    # labels.remove(os.path.basename(__file__))
    labels.remove('isAnagram')
    # labels.remove('myPow')
    # labels.remove('isPalindrome')
    # labels.remove('fib')

    map = {"fib":"FIB","isPalindrome":"PALIN","myPow":"POW","sortArray":"SORT"}

    total = 0
    correct = 0
    for label in labels:
        prgs = os.listdir('dataset_working'+'/'+label)
        if '__pycache__' in prgs:
            prgs.remove('__pycache__')
        ltotal = 0
        lcorrect = 0
        for prg in prgs:
            total += 1
            ltotal += 1
            print("Evaluating " + prg)
            loader = importlib.machinery.SourceFileLoader('dataset_working'+'/'+label, 'dataset_working'+'/'+label+'/'+prg)
            handle = loader.load_module('dataset_working'+'/'+label)
            s = handle.Solution()
            res = mp.predict(getattr(s, label),"python")
            oplabel = max(res,key=res.get)
            if(oplabel==map[label]):
                correct +=1
                lcorrect += 1
            print(res,label)
            print("Accuracy till "+ str(total)+" prgs: " + str((float(correct)/total)*100) )

        with open("results.txt",'a') as f:
            f.write("Accuracy of "+ label + " " + str(ltotal)+" prgs: " + str((float(lcorrect)/ltotal)*100)+"\n")
    
    return  (float(correct)/total)*100
# print(test())
print(evaluate())