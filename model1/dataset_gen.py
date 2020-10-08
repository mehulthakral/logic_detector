from numpy.random import seed
seed(0)
import tensorflow
tensorflow.random.set_seed(0)

import csv
from predict import Vector
import func
import random



def add_to_dataset(f,lang="python",name="dataset.csv"):
    ans=Vector(f,lang)

    ans.append(f)

    with open(name,"a",newline='') as file:
        writer=csv.writer(file)
        writer.writerow(ans)

def generate_dataset(nums=2):
    l=[f for f in dir(func) if '__' not in f]
    print(l)
    for i in range(nums):
        f=random.choice(l)
        add_to_dataset(f) 

generate_dataset()











