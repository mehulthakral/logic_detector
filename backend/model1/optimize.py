try:
    from . import optimizer
    from . import predict
    from . import dataset_gen
except:
    import optimizer
    import predict
    import dataset_gen
    

import inspect

def optimize(f,lang="python"):
    func_label=predict.predict(f,lang)
    approx_upper_bound,dataset_time_vector,dataset_function_source_str=optimizer.parse_dataset(func_label)
    if dataset_time_vector==None:
        return inspect.getsource(f)
    obj=optimizer.python(f,approx_upper_bound)
    func_time_vector=obj.generate_time_vector()
    if optimizer.greater_time_vector(dataset_time_vector,func_time_vector):
        return inspect.getsource(f)
    else:
        return dataset_function_source_str
    