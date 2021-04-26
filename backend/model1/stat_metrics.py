from radon.visitors import ComplexityVisitor, HalsteadVisitor
from radon.raw import analyze
from radon.metrics import h_visit, h_visit_ast
import subprocess
import decimal
import time
import os
import lizard

def cyclomatic_complexity(fnc_str,lang="python"):
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


def halstead(func_str,lang="python"):
    if lang=="python":
        vis = h_visit(func_str)
        # print(vis)
        res = {}
        keys = ["h1", "h2", "N1", "N2", "vocabulary", "length",
                "calculated_length", "volume", "Difficulty", "effort", "time", "bugs"]

        """ vis[0] returns for combined for multiple functions, ==> the total report """
        # print((vis[0], "\n", type(vis[0]))
        value = vis[0]
        res = dict(zip(keys, value))
        return res

        """ vis[1] contains list of each func separately """
        # res={}
        # for name, value in vis[1]:
        #     # print(name, value[0],len(value))
        #     res=dict(zip(keys, value))
        #     print(res)
    else:
        with open('code.txt', 'w') as f:
            # web_browsers = ['Firefox\n', 'Chrome\n', 'Edge\n']
            f.writelines(func_str)

        os.system("g++ halstead.cpp")
        time.sleep(2)
        out = subprocess.Popen(['./a.out'],  stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
        stdout,stderr = out.communicate()
        os.system("rm code.txt ./a.out")
        # print(type(stdout),stdout,"\n",stderr)
        lines = stdout.decode("utf-8")   #stdout is of types bytes, hence the conversion
        lines=lines.split('\n')
        halstead={}
        for i in lines:
            i=i.split(":")
            # print(i)
            if i[0] in ['n1','n2','N1','N2']:
                halstead[i[0]] = int(i[1])
            else:
                halstead[i[0]]=float(i[1])
        #print(halstead)
        return halstead


def other_metrics(fnc_str):
    stats = analyze(fnc_str)
    return stats


if __name__ == "__main__":

    code_sample = """
def factorial(n):
    if n < 2: 
        return 1
    return n * factorial(n - 1)
    
def foo(bar):
    #foo function
    return sum(i for i in range(bar ** 2) if bar % i)

def SORT(arr: list):
    n = len(arr)

    for i in range(n):
        for j in range(0, n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
    return arr
        """

    code_sample1 = """def strStr(a:str,b:str):
    def kmp_algo(needle):
        len_needle = len(needle)
        dp = [0] * len(needle)
        
        i = 1
        j = 0
        
        while i < len_needle:
            while j > 0 and needle[j] != needle[i]:
                j = dp[j-1]
            if needle[i] == needle[j]:
                j += 1
                dp[i] = j

            i += 1
        return dp

    def strStr(haystack: str, needle: str) -> int:
        if haystack == needle:
            return 0
        
        if not needle:
            return 0
        
        len_needle = len(needle)
        len_haystack = len(haystack)

        dp = kmp_algo(needle)
        
        i = 0
        j = 0
        
        while i < len_haystack:
            while j > 0 and haystack[i] != needle[j]:
                j = dp[j-1]

            if haystack[i] == needle[j]:
                j += 1            
            i += 1

            if j == len_needle:
                return i - j

        return -1


    return strStr(a,b)"""

    code_sample2 = """def strStr(a:str,b:str):
    def strStr(text: str, pat: str) -> int:
        if text==pat:
            return 0
        if pat=="":
            return 0
        def patlps(pat,lps,m):
            left=0
            i=1
            while i<m:
                if pat[left]==pat[i]:
                    left+=1
                    lps[i]=left
                    i+=1
                else:
                    if left!=0:
                        left=lps[left-1]
                    else:
                        lps[i]=0
                        i+=1
        n=len(text)
        m=len(pat)
        lps=[0]*m
        patlps(pat,lps,m)
        j=0
        i=0
        while i<n:
            if pat[j]==text[i]:
                i+=1
                j+=1
            if j==m:
                return i-j
            elif i<n and pat[j]!=text[i]:
                if j!=0:
                    j=lps[j-1]
                else:
                    i+=1
        return -1


    return strStr(a,b)"""

    code_sample3 = """def strStr(a:str,b:str):
    def strStr(text: str, pat: str) -> int:
        if text==pat:
            return 0
        if pat=="":
            return 0
        n=len(text)
        m=len(pat)
        lps=[0]*m
        j=0
        i=0
        while i<n:
            if pat[j]==text[i]:
                i+=1
                j+=1
            if j==m:
                return i-j
            elif i<n and pat[j]!=text[i]:
                if j!=0:
                    j=lps[j-1]
                else:
                    i+=1
        return -1


    return strStr(a,b)"""

    code_sample4 = "def MIN(l:list)->int:\n\treturn min(l)\n"

    # print(other_metrics(code_sample))
    # print(cyclomatic_complexity(code_sample))
    # print(halstead(code_sample))
    print(code_sample4)
    print(halstead(code_sample4))

# def factorial(n):
#     if n < 2:
#     	return 1
#     return n * factorial(n - 1)


# def foo(bar):
#     return sum(i for i in range(bar ** 2) if bar % i)


# def Trapezoid(self, order, coefficients, low, high, interval):
# 	self.N = (high - low)/interval
# 	self.I = sum([2*f(order, coefficients, low + (i*interval))
#                for i in range(1, int(self.N))])
# 	self.I += (f(order, coefficients, low) + f(order, coefficients, high))
# 	ans = (self.I*(high - low))/(2*self.N)
# 	self.graph(order, coefficients, low, high, interval, ans)
# 	return ans


# def solve(self, order, coefficients, low, high, method, interval=1e-3):
# 	if method == 'trapezoid':
# 	    return self.Trapezoid(order, coefficients, low, high, interval)
# 	elif method == 'simpson':
# 	    return self.Simpson(order, coefficients, low, high, interval)


# def SORT(arr: list):
# 	n = len(arr)

# 	for i in range(n):

# 	for j in range(0, n-i-1):

# 	if arr[j] > arr[j+1]:
# 	arr[j], arr[j+1] = arr[j+1], arr[j]
# 	return arr
