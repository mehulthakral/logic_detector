import lizard

def cyclomatic_complexity(fnc_str,lang):
    if lang=="python":
        i = lizard.analyze_file.analyze_source_code("input.py", fnc_str)
    else:
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
    if lang == "python":
        i = lizard.analyze_file.analyze_source_code("input.py", fnc_str)
    else:
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

    code3 = "    def strStr(a:str,b:str):\n            def kmp_algo(needle):\n\t        len_needle = len(needle)\n\t        dp = [0] * len(needle)\n\t        \n\t        i = 1\n\t        j = 0\n\t        \n\t        while i < len_needle:\n\t            while j > 0 and needle[j] != needle[i]:\n\t                j = dp[j-1]\n\t            if needle[i] == needle[j]:\n\t                j += 1\n\t                dp[i] = j\n\t\n\t            i += 1\n\t        return dp\n\t\n\t    def strStr(haystack: str, needle: str) -> int:\n\t        if haystack == needle:\n\t            return 0\n\t        \n\t        if not needle:\n\t            return 0\n\t        \n\t        len_needle = len(needle)\n\t        len_haystack = len(haystack)\n\t\n\t        dp = kmp_algo(needle)\n\t        \n\t        i = 0\n\t        j = 0\n\t        \n\t        while i < len_haystack:\n\t            while j > 0 and haystack[i] != needle[j]:\n\t                j = dp[j-1]\n\t\n\t            if haystack[i] == needle[j]:\n\t                j += 1            \n\t            i += 1\n\t\n\t            if j == len_needle:\n\t                return i - j\n\t\n\t        return -1\n\t\n\n        return strStr(a,b)\n"
    
    # print(otherMetrics(code1,"cpp"))
    # print(otherMetrics(code2, "python"))
    # print(cyclomatic_complexity(code1,"cpp"))
    # print(cyclomatic_complexity(code2,"python"))
    print(cyclomatic_complexity(code3,"python"))
    # print(i.function_list[0].__dict__)
    # print(i.function_list[1].__dict__)
