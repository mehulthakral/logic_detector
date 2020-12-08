import csv
import inspect
from typing import List, Set, Dict, Tuple, Optional

def add_to_dataset(choice,lang="python",dataset_name="model1/dataset.csv"):
    try:
        from . import languages
    except:
        import languages
    name,f=choice

    ans=languages.Vector(f,lang)

    ans.append(name)

    with open(dataset_name,"a",newline='') as file:
        writer=csv.writer(file)
        writer.writerow(ans)
        
def add_to_func(f,lang="python",dataset_name="model1/func.py"):
    file=open(dataset_name,"a")
    file.write("\n\n"+f)
    file.close()
    d={}
    exec(f,globals(),d)
    f=list(d.values())[0]
    return f.__name__,f
    

def generate_dataset(nums=5,lang="python",dataset_name="model1/dataset.csv"):
    import func
    l=[o for o in inspect.getmembers(func) if inspect.isfunction(o[1])]
    for i in l:
        for _ in range(nums):
            add_to_dataset(i,lang,dataset_name) 

if __name__=="__main__":
    generate_dataset(5,"python","dataset.csv")