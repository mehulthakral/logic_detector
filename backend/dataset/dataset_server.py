import os
import random
import importlib.machinery

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

print(test())