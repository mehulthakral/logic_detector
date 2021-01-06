try:
    from . import optimizer
    from . import predict
    from . import dataset
except:
    import optimizer
    import predict
    import dataset
    
import inspect

def change_func_name(func_str,func_name):
    func_str=func_str.split("def",1)
    func_str[1]=func_str[1].strip()
    func_str[1]=func_str[1].split("(",1)
    func_str[1][0]=func_name
    temp=""
    temp+=func_str[1][0]+"("
    for i in func_str[1][1:]:
        temp+=i 
    func_str[1]=temp
    return func_str[0]+"def "+func_str[1]
    

def optimize(f,lang="python"):
    func_label=predict.predict(f,lang)
    obj=dataset.json_dataset.read()
    if func_label not in obj:
        return inspect.getsource(f)
    approx_upper_bound,dataset_time_vector,dataset_function_source_str=obj[func_label]
    pobj=optimizer.python(f,approx_upper_bound)
    func_time_vector=pobj.generate_vector()
    if optimizer.greater_vector(dataset_time_vector,func_time_vector):
        return inspect.getsource(f)
    else:
        f_name=f.__name__
        return change_func_name(dataset_function_source_str,f_name)