import os
import random
import importlib.machinery
import model1.predict as mp

def test():
    # print(os.listdir('.'))
    labels = os.listdir('.')
    labels.remove(os.path.basename(__file__))
    # print(labels)
    label = random.choice(labels)
    # print(label)
    prgs = os.listdir(label)
    if '__pycache__' in prgs:
        prgs.remove('__pycache__')
    prg = random.choice(prgs)
    # print(prg)
    loader = importlib.machinery.SourceFileLoader(label, label+'/'+prg)
    handle = loader.load_module(label)
    s = handle.Solution()
    return getattr(s, label)
    # return s.label

# def test():
#     # print(os.listdir('.'))
#     labels = os.listdir('dataset')
#     # labels.remove(os.path.basename(__file__))
#     # print(labels)
#     label = random.choice(labels)
#     # print(label)
#     prgs = os.listdir('dataset'+'/'+label)
#     if '__pycache__' in prgs:
#         prgs.remove('__pycache__')
#     prg = random.choice(prgs)
#     # print(prg)
#     loader = importlib.machinery.SourceFileLoader('dataset'+'/'+label, 'dataset'+'/'+label+'/'+prg)
#     handle = loader.load_module('dataset'+'/'+label)
#     s = handle.Solution()
#     return getattr(s, label)
#     # return s.label


def evaluate():
    labels = os.listdir('dataset')
    # labels.remove(os.path.basename(__file__))
    labels.remove('isAnagram')

    total = 0
    correct = 0
    for label in labels:
        prgs = os.listdir('dataset'+'/'+label)
        if '__pycache__' in prgs:
            prgs.remove('__pycache__')
        for prg in prgs:
            loader = importlib.machinery.SourceFileLoader('dataset'+'/'+label, 'dataset'+'/'+label+'/'+prg)
            handle = loader.load_module('dataset'+'/'+label)
            s = handle.Solution()
            res = mp.predict(getattr(s, label),"python")
            print(res)

# print(test())
evaluate()