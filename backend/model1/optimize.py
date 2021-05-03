try:
    from . import optimizer
    from . import predict
    from . import dataset
    from . import stat_metrics
except:
    import optimizer
    import predict
    import dataset
    import stat_metrics

import inspect
import pandas as pd
from typing import List, Set, Dict, Tuple, Optional

Mode = "Test" #Test or Exec

def change_func_name(func_str, new_func_name, old_func_name):
    """
    func_str = func_str.split("def", 1)
    func_str[1] = func_str[1].strip()
    func_str[1] = func_str[1].split("(", 1)
    func_str[1][0] = func_name
    temp = ""
    temp += func_str[1][0]+"("
    for i in func_str[1][1:]:
        temp += i
    func_str[1] = temp
    return func_str[0]+"def "+func_str[1]
    """
    return func_str.replace(old_func_name,new_func_name)

def isIterable(f):
    try:
        iterator = iter(f)
    except TypeError:
        return False
    else:
        return True

def optimize(func_tuple, lang="python", weights=[1, 0, 0, 0]):

    """
    if lang!="python":
        weights[1]=0
    """
    if not isIterable(func_tuple):
        f=func_tuple
        func_str=inspect.getsource(f)  
        func_tuple=(f,func_str) 
        
    f,func_str=func_tuple
    func_label = predict.predict(f, lang)
    obj = dataset.json_dataset.read(lang)
    if func_label not in obj:
        return func_str


    dataset_list = obj[func_label][1:]

    pobj = optimizer.optimizer(func_tuple,lang)
    func_time_vector, func_mem_vector = pobj.generate_vector()
    # print(func_mem_vector)
    integral = optimizer.get_integral
    cyclo = stat_metrics.cyclomatic_complexity
    metric_vector = [integral(func_time_vector), integral(
        func_mem_vector), cyclo(func_str, lang)[f.__name__], stat_metrics.halstead(func_str,lang)["Difficulty"]]
    print(metric_vector)
    dataset_list.append([metric_vector[0],metric_vector[1],metric_vector[2],metric_vector[3],func_str])
    scaled_dataset_list = optimizer.scale(dataset_list)
    # print(scaled_dataset_list)
    func_metric_val = optimizer.get_metric_val(scaled_dataset_list[-1][:4], weights)
    scaled_dataset_list.pop()
    scaled_dataset_list.sort(key=lambda x: optimizer.get_metric_val(x, weights))
    dataset_min_metric_val = optimizer.get_metric_val(scaled_dataset_list[0], weights)
    dataset_function_source_str = scaled_dataset_list[0][4]
    print(dataset_min_metric_val, func_metric_val)

    if dataset_min_metric_val >= func_metric_val:
        return func_str
    else:
        f_name = f.__name__
        temp_d = {}
        if lang=="python":
            exec(dataset_function_source_str,globals(),temp_d)
            return change_func_name(dataset_function_source_str, f_name, temp_d[list(temp_d.keys())[0]].__name__)
        else:
            return dataset_function_source_str


def rank(f_arr, lang="python", weights=[1, 0, 0, 0], top_no=None):
    for i in range(len(f_arr)):
        if not isIterable(f_arr[i]):
            f_arr[i]=[f_arr[i],inspect.getsource(f_arr[i])]
    ans = []
    obj = dataset.json_dataset.read(lang)

    if top_no == None:
        top_no = len(obj)

    integral = optimizer.get_integral
    cyclo = stat_metrics.cyclomatic_complexity
    s = set()
    for f, func_str in f_arr:
        func_label = predict.predict(f, lang)
        if func_label not in obj:
            ans.append([float("inf"), func_str])
        else:

            pobj = optimizer.optimizer((f,func_str), lang)
            func_time_vector, func_mem_vector = pobj.generate_vector()
            metric_vector = [integral(func_time_vector), integral(
                func_mem_vector), cyclo(func_str, lang)[f.__name__], stat_metrics.halstead(func_str,lang)["Difficulty"]]
            dataset_list = obj[func_label][1:]
            dataset_list.append([metric_vector[0],metric_vector[1],metric_vector[2],metric_vector[3],func_str])
            scaled_dataset_list = optimizer.scale(dataset_list)
            func_metric_val = optimizer.get_metric_val(scaled_dataset_list[-1][:4], weights)
            scaled_dataset_list.pop()
            ans.append([func_metric_val, func_str, True])
            if func_label not in s:
                s.add(func_label)
                for i in scaled_dataset_list:
                    func_metric_val = optimizer.get_metric_val(i, weights)
                    ans.append([func_metric_val, i[-1]])
                if Mode == "Test":
                    test_ans =[]
                    for i in range(len(scaled_dataset_list)):
                        test_ans.append([func_label] + dataset_list[i] + [ans[i+1][0],ans[i+1][1]] + scaled_dataset_list[i][:4])
                    #print(test_ans)
                    df = pd.DataFrame(test_ans,columns=["Label", "Time", "Space", "Cyclomatic", "Halstead", "Composite Metric", "Code", "Scaled_Time", "Scaled_Space", "Scaled_Cyclomatic", "Scaled_Halstead"])
                    df.Code = df.Code.apply(lambda x : x.replace('\n', '\\n')) 
                    df.index+=1
                    df["Index"] = df.index
                    df['Model_Rank'] = df['Composite Metric'].rank()
                    df.to_csv("model1/Model_Output.csv", index = False, header=True)
    ans.sort()
    count = 0
    new_ans = ans[:top_no]
    for i in range(len(new_ans)):
        if len(new_ans[i]) == 3:
            new_ans[i][2] = i+1
            count += 1

    if count == len(f_arr):
        return new_ans
    else:
        for i in range(len(new_ans), len(ans)):
            if len(new_ans[i]) == 3:
                new_ans[i][2] = i+1
                count += 1
                new_ans.append(ans[i])

        return new_ans


def rank_test(func_label, lang="python", weights=[1, 0, 0, 0]):
    ans = []
    obj = dataset.json_dataset.read(lang)

    top_no = len(obj)

    integral = optimizer.get_integral
    cyclo = stat_metrics.cyclomatic_complexity
    s = set()
    if func_label not in obj:
        print("Label not present in dataset")
        return "No Label"
    else:
        dataset_list = obj[func_label][1:]
        scaled_dataset_list = optimizer.scale(dataset_list)
        func_metric_val = optimizer.get_metric_val(scaled_dataset_list[-1][:4], weights)
        #scaled_dataset_list.pop()
        if func_label not in s:
            s.add(func_label)
            for i in scaled_dataset_list:
                func_metric_val = optimizer.get_metric_val(i, weights)
                ans.append([func_metric_val, i[-1]])
            test_ans =[]
            for i in range(len(scaled_dataset_list)):
                test_ans.append([func_label] + dataset_list[i] + [ans[i][0],ans[i][1]] + scaled_dataset_list[i][:4])
                #print(test_ans)
            df = pd.DataFrame(test_ans,columns=["Label", "Time", "Space", "Cyclomatic", "Halstead", "Composite Metric", "Code", "Scaled_Time", "Scaled_Space", "Scaled_Cyclomatic", "Scaled_Halstead"])
            df.Code = df.Code.apply(lambda x : x.replace('\n', '\\n')) 
            df.index+=1
            df["Index"] = df.index
            df['Model_Rank'] = df['Composite Metric'].rank(method="dense")
            #df.to_csv("Model_Output.csv", index = False, header=True)
            return df


def compare(f_arr, lang="python", weights=[1, 0, 0, 0]):
    for i in range(len(f_arr)):
        if not isIterable(f_arr[i]):
            f_arr[i]=[f_arr[i],inspect.getsource(f_arr[i])]
    ans = []
    metric_values = []
    integral = optimizer.get_integral
    cyclo = stat_metrics.cyclomatic_complexity
    for f, func_str in f_arr:
        pobj = optimizer.optimizer((f,func_str), lang)
        func_time_vector, func_mem_vector = pobj.generate_vector()
        metric_vector = [integral(func_time_vector), integral(
            func_mem_vector), cyclo(func_str, lang)[f.__name__],stat_metrics.halstead(func_str,lang)["Difficulty"]]
        metric_values.append([metric_vector[0],metric_vector[1],metric_vector[2],metric_vector[3],f.__name__])

    scaled_metric_values = optimizer.scale(metric_values)
    
    for values in scaled_metric_values:
        func_metric_val = optimizer.get_metric_val(values[:4], weights)
        f_name = values[4]
        ans.append([func_metric_val, f_name])

    ans.sort()

    return ans
