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

    approx_upper_bound = obj[func_label][0]
    dataset_list = obj[func_label][1:]
    sorted(dataset_list, key=optimizer.get_metric_val)
    dataset_min_metric_val = optimizer.get_metric_val(dataset_list[0])
    dataset_function_source_str = dataset_list[0][4]

    pobj=optimizer.python(f,approx_upper_bound)
    func_time_vector,func_mem_vector = pobj.generate_vector()
    print(func_mem_vector)
    integral = optimizer.get_integral
    func_metric_val = optimizer.get_metric_val([integral(func_time_vector),integral(func_mem_vector),0,0])

    if dataset_min_metric_val>=func_metric_val:
        return inspect.getsource(f)
    else:
        f_name=f.__name__
        return change_func_name(dataset_function_source_str,f_name)