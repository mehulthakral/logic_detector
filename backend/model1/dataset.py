import csv
import inspect
from typing import List, Set, Dict, Tuple, Optional
import json
class csv_dataset:
    def add(self,choice,lang="python"):
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

    def generate(self,nums=5,lang="python"):
        import func
        functions=[o for o in inspect.getmembers(func) if inspect.isfunction(o[1])]
        for i in functions:
            for _ in range(nums):
                csv_dataset.add(i,lang) 


class json_dataset:
    @staticmethod
    def read():
        try:
            fobj=open("model1/dataset.json")
        except:
            fobj=open("dataset.json")
        data=fobj.read()
        if data=="":
            return {}
        obj=json.loads(data)
        fobj.close()
        return obj
    
    @staticmethod
    def write(obj):
        try:
            fobj=open("model1/dataset.json","w")
        except:
            fobj=open("dataset.json","w")
        data=json.dumps(obj,indent="\t")
        fobj.write(data)
        fobj.close()  
        
    @staticmethod
    def add(choice,lang="python"):
        try:
            from . import optimizer
        except:
            import optimizer
            
        name,f=choice
        obj=json_dataset.read()
        if name in obj:
            approx_upper_bound,dataset_time_vector,dataset_function_source_str=obj[name]
            pobj=optimizer.python(f,approx_upper_bound)
            function_time_vector=pobj.generate_vector()
            if optimizer.greater_time_vector(dataset_time_vector,function_time_vector):
                dataset_function_source_str=inspect.getsource(f)
                obj[name]=[approx_upper_bound,function_time_vector,dataset_function_source_str]
                json_dataset.write(obj)
        else:
            pobj=optimizer.python(f)
            function_time_vector=pobj.generate_vector()
            approx_upper_bound=optimizer.get_approx_upper_bound(function_time_vector)
            dataset_function_source_str=inspect.getsource(f)
            obj[name]=[approx_upper_bound,function_time_vector,dataset_function_source_str]
            json_dataset.write(obj)
              
    @staticmethod
    def generate(nums=1,lang="python"):
        import func 
        functions=[o for o in inspect.getmembers(func) if inspect.isfunction(o[1])]
        for i in functions:
            json_dataset.add(i,lang)

if __name__=="__main__":
    import func
    json_dataset.add(("MAX",func.MAX))