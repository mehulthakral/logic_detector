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
            fobj=open("model1/dataset1.json")
        except:
            fobj=open("dataset1.json")
        data=fobj.read()
        if data=="":
            return {}
        obj=json.loads(data)
        fobj.close()
        return obj
    
    @staticmethod
    def write(obj):
        try:
            fobj=open("model1/dataset1.json","w")
        except:
            fobj=open("dataset1.json","w")
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
            # dataset_time_vector,dataset_function_source_str = obj[name]
            # approx_upper_bound = optimizer.get_approx_upper_bound(dataset_time_vector)
            # pobj = optimizer.python(f,approx_upper_bound)
            # function_time_vector,func_mem_vector = pobj.generate_vector()
            # if optimizer.greater_time_vector(dataset_time_vector,function_time_vector):
            #     dataset_function_source_str = inspect.getsource(f)
            #     obj[name]=[approx_upper_bound,function_time_vector,dataset_function_source_str]
            #     json_dataset.write(obj)

            func_label = name
            approx_upper_bound = obj[func_label][0]
            dataset_list = obj[func_label][1:]
            sorted(dataset_list, key=optimizer.get_metric_val)
            dataset_min_metric_val = optimizer.get_metric_val(dataset_list[0])
            dataset_function_source_str = dataset_list[0][4]

            pobj=optimizer.python(f,approx_upper_bound)
            func_time_vector,func_mem_vector = pobj.generate_vector()
            print(func_time_vector,func_mem_vector)
            func_time_metric_val = optimizer.get_integral(func_time_vector)
            func_mem_metric_val = optimizer.get_integral(func_mem_vector)
            func_metric_val = optimizer.get_metric_val([func_time_metric_val,func_mem_metric_val,0,0])

            if dataset_min_metric_val>=func_metric_val:
                print("Better than dataset")
            func_source_str = inspect.getsource(f)
            obj[name].append([func_time_metric_val,func_mem_metric_val,0,0,func_source_str])
            json_dataset.write(obj)
            
        else:
            print("Not available in dataset")
            pobj=optimizer.python(f)
            func_time_vector,func_mem_vector = pobj.generate_vector()
            print(func_time_vector,func_mem_vector)
            approx_upper_bound=optimizer.get_approx_upper_bound(func_time_vector)
            func_time_metric_val = optimizer.get_integral(func_time_vector)
            func_mem_metric_val = optimizer.get_integral(func_mem_vector)
            func_source_str=inspect.getsource(f)
            obj[name]=[approx_upper_bound,[func_time_metric_val,func_mem_metric_val,0,0,func_source_str]]
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