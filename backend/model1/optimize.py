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
    obj=dataset.json_dataset.read(lang)
    if func_label not in obj:
        return inspect.getsource(f)

    approx_upper_bound = obj[func_label][0]
    dataset_list = obj[func_label][1:]
    dataset_list.sort(key=lambda x: optimizer.get_metric_val(x, weights))
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
        return func_str
    else:
        f_name=f.__name__
        return change_func_name(dataset_function_source_str,f_name)
    
def rank(f_arr,lang="python",weights=[1,0,0,0],top_no=None):
    ans=[]
    obj=dataset.json_dataset.read(lang)
    
    if top_no==None:
        top_no=len(obj)
        
    integral = optimizer.get_integral
    cyclo = cyclomatic.cyclomatic_complexity
    s=set()
    for f,func_str in f_arr:
        func_label=predict.predict(f,lang)
        if func_label not in obj:
            ans.append([float("inf"),func_str])
        else:
            approx_upper_bound = obj[func_label][0]
            pobj=optimizer.optimizer(f,approx_upper_bound)
            func_time_vector,func_mem_vector = pobj.generate_vector()
            metric_vector = [integral(func_time_vector), integral(func_mem_vector), cyclo(func_str, lang)[f.__name__], 0]
            func_metric_val = optimizer.get_metric_val(metric_vector,weights)
            ans.append([func_metric_val,func_str,True])
            if func_label not in s:
                s.add(func_label)
                for i in obj[func_label][1:]:
                    func_metric_val = optimizer.get_metric_val(i,weights)
                    ans.append([func_metric_val,i[-1]])
    ans.sort()
    count=0
    new_ans=ans[:top_no]
    for i in range(len(new_ans)):
        if len(new_ans[i])==3:
            new_ans[i][2]=i+1
            count+=1
    
    if count==len(f_arr):
        return new_ans
    else:
        for i in range(len(new_ans),len(ans)):
            if len(new_ans[i])==3:
                new_ans[i][2]=i+1
                count+=1
                new_ans.append(ans[i])
    
        return new_ans

def compare(f_arr,lang="python",weights=[1,0,0,0]):
    ans=[]
    integral = optimizer.get_integral
    cyclo = cyclomatic.cyclomatic_complexity
    
    for f,func_str in f_arr:
        approx_upper_bound = "n"
        pobj=optimizer.optimizer(f,approx_upper_bound)
        func_time_vector,func_mem_vector = pobj.generate_vector()
        metric_vector = [integral(func_time_vector), integral(func_mem_vector), cyclo(func_str, lang)[f.__name__], 0]
        func_metric_val = optimizer.get_metric_val(metric_vector,weights)
        f_name=f.__name__
        ans.append([func_metric_val,f_name])
    
    ans.sort()
    
    return ans
    