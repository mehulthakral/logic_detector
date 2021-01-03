import csv
import inspect
from typing import List, Set, Dict, Tuple, Optional
import json
def add_to_csv_dataset(choice,lang="python"):
    try:
        from . import predictor
    except:
        import predictor
    name,f=choice

    vobj=predictor.python(f)
    ans =vobj.generate_vector()

    ans.append(name)
    try:
        with open("model1/dataset.csv","a",newline='') as file:
            writer=csv.writer(file)
            writer.writerow(ans)
    except:
        with open("dataset.csv","a",newline='') as file:
            writer=csv.writer(file)
            writer.writerow(ans)       

def generate_csv_dataset(nums=5,lang="python"):
    import func
    functions=[o for o in inspect.getmembers(func) if inspect.isfunction(o[1])]
    for i in functions:
        for _ in range(nums):
            add_to_csv_dataset(i,lang) 

def add_to_json_dataset(choice,lang="python"):
    try:
        from . import optimizer
    except:
        import optimizer
        
    name,f=choice
    def open_f(mode="r"):
        try:
            fobj=open("model1/dataset.json",mode)
        except:
            fobj=open("dataset.json",mode)
        return fobj 
    fobj=open_f()
    data=fobj.read()
    if data=="":
        obj={}
    else:
        obj=json.loads(data)
    fobj.close()
    if name in obj:
        approx_upper_bound,dataset_time_vector,dataset_function_source_str=obj[name]
        pobj=optimizer.python(f,approx_upper_bound)
        function_time_vector=pobj.generate_time_vector()
        if optimizer.greater_time_vector(dataset_time_vector,function_time_vector):
            dataset_function_source_str=inspect.getsource(f)
            obj[name]=[approx_upper_bound,function_time_vector,dataset_function_source_str]
            fobj=open_f("w")
            fobj.write(json.dumps(obj))
            fobj.close()
    else:
        pobj=optimizer.python(f)
        function_time_vector=pobj.generate_time_vector()
        approx_upper_bound=optimizer.get_approx_upper_bound(function_time_vector)
        dataset_function_source_str=inspect.getsource(f)
        obj[name]=[approx_upper_bound,function_time_vector,dataset_function_source_str]
        fobj=open_f("w")
        fobj.write(json.dumps(obj))
        fobj.close()     

def generate_json_dataset(nums=1,lang="python"):
    import func 
    functions=[o for o in inspect.getmembers(func) if inspect.isfunction(o[1])]
    for i in functions:
        add_to_json_dataset(i,lang)

if __name__=="__main__":
    #generate_csv_dataset(5)
    import func
    add_to_json_dataset(("MIN",func.MIN))