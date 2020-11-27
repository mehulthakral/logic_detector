import csv
import inspect

def add_to_dataset(choice,lang="python",dataset_name="model1/dataset.csv"):
    from . import languages
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
    

def generate_dataset(nums=5):
    import languages
    import func
    l=[o for o in inspect.getmembers(func) if inspect.isfunction(o[1])]
    for _ in range(nums):
        for i in l:
            add_to_dataset(i,"python","dataset.csv") 

if __name__=="__main__":
    generate_dataset()