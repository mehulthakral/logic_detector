import csv
import func
import random
import languages 

import inspect

def add_to_dataset(choice,lang="python",dataset_name="dataset.csv"):

    name,f=choice

    ans=languages.Vector(f,lang)

    ans.append(name)

    with open(dataset_name,"a",newline='') as file:
        writer=csv.writer(file)
        writer.writerow(ans)

def generate_dataset(nums=10):
    l=[o for o in inspect.getmembers(func) if inspect.isfunction(o[1])]
    
    for _ in range(nums):
        for i in l:
            add_to_dataset(i) 

generate_dataset()











