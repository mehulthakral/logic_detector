try:
    from . import optimizer
    from . import predict
    from . import cyclomatic
    from . import dataset
    from . import pymetrics
except:
    import optimizer
    import predict
    import dataset
    import cyclomatic
    import pymetrics

import inspect
import pandas as pd

Mode = "Test" #Test or Exec

def change_func_name(func_str, func_name):
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


def optimize(func_tuple, lang="python", weights=[1, 0, 0, 0]):
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
    cyclo = cyclomatic.cyclomatic_complexity
    metric_vector = [integral(func_time_vector), integral(
        func_mem_vector), cyclo(func_str, lang)[f.__name__], pymetrics.halstead(func_str,lang)["difficulty"]]
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
        return change_func_name(dataset_function_source_str, f_name)


def rank(f_arr, lang="python", weights=[1, 0, 0, 0], top_no=None):
    ans = []
    obj = dataset.json_dataset.read(lang)

    if top_no == None:
        top_no = len(obj)

    integral = optimizer.get_integral
    cyclo = cyclomatic.cyclomatic_complexity
    s = set()
    for f, func_str in f_arr:
        func_label = predict.predict(f, lang)
        if func_label not in obj:
            ans.append([float("inf"), func_str])
        else:

            pobj = optimizer.optimizer((f,func_str), lang)
            func_time_vector, func_mem_vector = pobj.generate_vector()
            metric_vector = [integral(func_time_vector), integral(
                func_mem_vector), cyclo(func_str, lang)[f.__name__], pymetrics.halstead(func_str,lang)["difficulty"]]
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
                        test_ans.append([ans[i+1][0],ans[i+1][1]] + dataset_list[i])
                    #print(test_ans)
                    df = pd.DataFrame(test_ans,columns=["Composite Metric","Code","Time","Space","Cyclomatic","Halstead"])
                    df.Code = df.Code.apply(lambda x : x.replace('\n', '\\n')) 
                    df.index+=1
                    df.to_csv(r'Model_Output.csv', index = True, header=True)
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


def compare(f_arr, lang="python", weights=[1, 0, 0, 0]):
    ans = []
    metric_values = []
    integral = optimizer.get_integral
    cyclo = cyclomatic.cyclomatic_complexity
    for f, func_str in f_arr:
        pobj = optimizer.optimizer((f,func_str), lang)
        func_time_vector, func_mem_vector = pobj.generate_vector()
        metric_vector = [integral(func_time_vector), integral(
            func_mem_vector), cyclo(func_str, lang)[f.__name__],pymetrics.halstead(func_str,lang)["difficulty"]]
        metric_values.append([metric_vector[0],metric_vector[1],metric_vector[2],metric_vector[3],f.__name__])

    scaled_metric_values = optimizer.scale(metric_values)
    
    for values in scaled_metric_values:
        func_metric_val = optimizer.get_metric_val(values[:4], weights)
        f_name = values[4]
        ans.append([func_metric_val, f_name])

    ans.sort()

    return ans
