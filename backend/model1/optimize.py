try:
    from . import optimizer
    from . import predict
    from . import cyclomatic
    from . import dataset
except:
    import optimizer
    import predict
    import dataset
    import cyclomatic

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
    

def optimize(f,lang="python",weights=[1,0,0,0]):
    func_label=predict.predict(f,lang)
    obj=dataset.json_dataset.read()
    if func_label not in obj:
        return inspect.getsource(f)

    approx_upper_bound = obj[func_label][0]
    dataset_list = obj[func_label][1:]
    sorted(dataset_list, key=lambda x: optimizer.get_metric_val(x, weights))
    dataset_min_metric_val = optimizer.get_metric_val(dataset_list[0], weights)
    dataset_function_source_str = dataset_list[0][4]

    pobj=optimizer.optimizer(f,approx_upper_bound)
    func_time_vector,func_mem_vector = pobj.generate_vector()
    # print(func_mem_vector)
    integral = optimizer.get_integral
    func_str = inspect.getsource(f)
    cyclo = cyclomatic.cyclomatic_complexity
    metric_vector = [integral(func_time_vector), integral(
        func_mem_vector), cyclo(func_str, lang)[f.__name__], 0]
    print(metric_vector)
    func_metric_val = optimizer.get_metric_val(metric_vector,weights)
    print(dataset_min_metric_val, func_metric_val)

    if dataset_min_metric_val>=func_metric_val:
        return inspect.getsource(f)
    else:
        f_name=f.__name__
        return change_func_name(dataset_function_source_str,f_name)
