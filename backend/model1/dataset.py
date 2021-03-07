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

        vobj=predictor.predictor(f)
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
    def read(lang="python"):
        fobj = None
        if(lang=="python"):
            try:
                fobj=open("model1/dataset_py.json")
            except:
                fobj=open("dataset_py.json")
        else:
            try:
                fobj=open("model1/dataset_cpp.json")
            except:
                fobj=open("dataset_cpp.json")

        data=fobj.read()
        if data=="":
            return {}
        obj=json.loads(data)
        fobj.close()
        return obj
    
    @staticmethod
    def write(obj,lang="python"):
        fobj = None
        if(lang=="python"):
            try:
                fobj=open("model1/dataset_py.json","w")
            except:
                fobj=open("dataset_py.json","w")
        else:
            try:
                fobj=open("model1/dataset_cpp.json","w")
            except:
                fobj=open("dataset_cpp.json","w")

        data=json.dumps(obj,indent="\t")
        fobj.write(data)
        fobj.close()  
        
    @staticmethod
    def add(choice,lang="python"):
        try:
            from . import optimizer
            from . import cyclomatic
        except:
            import optimizer
            import cyclomatic
            
        name, f, label, fn_src = None, None, None, None

        if(len(choice)==2):
            name,f=choice
        else:
            name, f, label, fn_src = choice

        obj=json_dataset.read(lang)
        if name in obj:

            print("Available in the dataset")
            func_label = name
            approx_upper_bound = obj[func_label][0]

            pobj=optimizer.optimizer(f,approx_upper_bound)
            func_time_vector,func_mem_vector = pobj.generate_vector()
            print(func_time_vector,func_mem_vector)
            func_time_metric_val = optimizer.get_integral(func_time_vector)
            func_mem_metric_val = optimizer.get_integral(func_mem_vector)
            cyclo = cyclomatic.cyclomatic_complexity
            
            func_source_str = inspect.getsource(f)
            # print("Before: ",func_source_str)

            if(label):
                func_source_str = func_source_str.replace("global f",fn_src)
                func_source_str = func_source_str.replace("f(",label+'(')
                func_source_str = func_source_str.replace("self, ","")
                func_source_str = func_source_str.replace("self,","")
                func_source_str = func_source_str.replace("self.","")

            print(func_source_str)
            func_cyclo_metric_val = cyclo(func_source_str, lang)[f.__name__]
            obj[name].append([func_time_metric_val,func_mem_metric_val,func_cyclo_metric_val,0,func_source_str])
            json_dataset.write(obj,lang)
            
        else:
            print("Not available in dataset")
            pobj=optimizer.optimizer(f)
            func_time_vector,func_mem_vector = pobj.generate_vector()
            print(func_time_vector,func_mem_vector)
            approx_upper_bound=optimizer.get_approx_upper_bound(func_time_vector)
            func_time_metric_val = optimizer.get_integral(func_time_vector)
            func_mem_metric_val = optimizer.get_integral(func_mem_vector)
            cyclo = cyclomatic.cyclomatic_complexity
            func_source_str=inspect.getsource(f)
            # print("Before: ",func_source_str)

            if(label):
                func_source_str = func_source_str.replace("global f",fn_src)
                func_source_str = func_source_str.replace("f(",label+'(')
                func_source_str = func_source_str.replace("self, ","")
                func_source_str = func_source_str.replace("self,","")
                func_source_str = func_source_str.replace("self.","")

            print(func_source_str)
            func_cyclo_metric_val = cyclo(func_source_str, lang)[f.__name__]
            obj[name]=[approx_upper_bound,[func_time_metric_val,func_mem_metric_val,func_cyclo_metric_val,0,func_source_str]]
            json_dataset.write(obj,lang)
              
    @staticmethod
    def generate(nums=1,lang="python"):
        import func 
        functions=[o for o in inspect.getmembers(func) if inspect.isfunction(o[1])]
        for i in functions:
            json_dataset.add(i,lang)

if __name__=="__main__":
    import func
    json_dataset.add(("MAX",func.MAX))