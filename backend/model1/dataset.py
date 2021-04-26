import csv
import inspect
from typing import List, Set, Dict, Tuple, Optional
import json
class csv_dataset:
    
    @staticmethod
    def add(choice,lang="python"):
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
                    
    @staticmethod
    def generate(nums=3,lang="python"):
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
            from . import stat_metrics
        except:
            import optimizer
            import stat_metrics
            
        name, f, label, fn_src = choice

        obj=json_dataset.read(lang)
        if name in obj:

            print("Available in the dataset")
            func_label = name

            pobj=optimizer.optimizer((f,fn_src),lang)
            func_time_vector,func_mem_vector = pobj.generate_vector()
            print(func_time_vector,func_mem_vector)
            func_time_metric_val = optimizer.get_integral(func_time_vector)
            func_mem_metric_val = optimizer.get_integral(func_mem_vector)
            cyclo = stat_metrics.cyclomatic_complexity
            
            if lang=="python":
                func_source_str = inspect.getsource(f)
            else:
                func_source_str = fn_src
            # print("Before: ",func_source_str)

            if(label and lang=="python"):
                func_source_str = func_source_str.replace("\n    ","\n")
                func_source_str = func_source_str.replace("    def","def",1)
                func_source_str = func_source_str.replace("global f",fn_src)
                func_source_str = func_source_str.replace(" f(",' '+label+'(')
                func_source_str = func_source_str.replace("self, ","")
                func_source_str = func_source_str.replace("self,","")
                func_source_str = func_source_str.replace("self.","")

            print(func_source_str)
            func_cyclo_metric_val = sum(cyclo(func_source_str, lang).values())
            func_diff_metric_val = stat_metrics.halstead(func_source_str,lang)["Difficulty"]
            obj[name].append([func_time_metric_val,func_mem_metric_val,func_cyclo_metric_val,func_diff_metric_val,func_source_str])
            json_dataset.write(obj,lang)
            
        else:
            print("Not available in dataset")
            pobj=optimizer.optimizer((f,fn_src),lang)
            func_time_vector,func_mem_vector = pobj.generate_vector()
            print(func_time_vector,func_mem_vector)
            approx_upper_bound=optimizer.get_approx_upper_bound(func_time_vector)
            func_time_metric_val = optimizer.get_integral(func_time_vector)
            func_mem_metric_val = optimizer.get_integral(func_mem_vector)
            cyclo = stat_metrics.cyclomatic_complexity
            
            if lang=="python":
                func_source_str = inspect.getsource(f)
            else:
                func_source_str = fn_src
            # print("Before: ",func_source_str)

            if((label and lang=="python")):
                func_source_str = func_source_str.replace("\n    ","\n")
                func_source_str = func_source_str.replace("    def","def",1)
                func_source_str = func_source_str.replace("global f",fn_src)
                func_source_str = func_source_str.replace(" f(",' '+label+'(')
                func_source_str = func_source_str.replace("self, ","")
                func_source_str = func_source_str.replace("self,","")
                func_source_str = func_source_str.replace("self.","")

            print(func_source_str)
            func_cyclo_metric_val = sum(cyclo(func_source_str, lang).values())
            func_diff_metric_val = stat_metrics.halstead(func_source_str,lang)["Difficulty"]
            obj[name]=[approx_upper_bound,[func_time_metric_val,func_mem_metric_val,func_cyclo_metric_val,func_diff_metric_val,func_source_str]]
            json_dataset.write(obj,lang)
              
    @staticmethod
    def generate(nums=1,lang="python"):
        import func 
        functions=[[o[0],o[1],o[1].__name__,inspect.getsource(o[1])] for o in inspect.getmembers(func) if inspect.isfunction(o[1])]
        for i in functions:
            json_dataset.add(i,lang)

if __name__=="__main__":
    csv_dataset.generate()