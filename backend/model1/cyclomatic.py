import lizard

def cyclomatic_complexity(fnc_str,lang):
    if lang=="py":
        i = lizard.analyze_file.analyze_source_code("input.py", fnc_str)
    if lang=="cpp":
        i = lizard.analyze_file.analyze_source_code("input.cpp", fnc_str)

    """ iterate over funcs in the input snippet """
    res={}
    for f in i.function_list:
        d = f.__dict__
        #print(d)
        # print(d["name"],d["cyclomatic_complexity"])
        res[d["name"]]=d["cyclomatic_complexity"]

   
    return res


def otherMetrics(fnc_str,lang):
    if lang == "py":
        i = lizard.analyze_file.analyze_source_code("input.py", fnc_str)
    if lang=="cpp":
        i = lizard.analyze_file.analyze_source_code("input.cpp", fnc_str)
    
    # print(i.__dict__)
    # to see the complete lizard function object
    # print(i.function_list[0].__dict__)  
    res={}
    for f in i.function_list:
        d=f.__dict__
        res[d["name"]]={"token_count":d["token_count"],"nloc":d["nloc"]}

    return res


if __name__ == "__main__":

    code1="""
    
    void bubbleSort(int arr[], int n)  
{  
    int i, j;  
    for (i = 0; i < n-1; i++)      
      
    // Last i elements are already in place  
    for (j = 0; j < n-i-1; j++)  
        if (arr[j] > arr[j+1])  
            swap(&arr[j], &arr[j+1]);  
}     
    """
    code2 = """
def bubble(arr: list):
    n = len(arr)
    for i in range(n):
        for j in range(0, n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
    return arr
            """

    
    print(otherMetrics(code1,"cpp"))
    print(otherMetrics(code2, "py"))
    print(cyclomatic_complexity(code1,"cpp"))
    print(cyclomatic_complexity(code2,"py"))
    # print(i.function_list[0].__dict__)
    # print(i.function_list[1].__dict__)
