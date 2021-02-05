
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

from radon.visitors import ComplexityVisitor
from radon.raw import analyze
code_sample1 = """
def _split_tokens(tokens, token, value):
    '''Split a list of tokens on the specified token pair (token, value),
    where *token* is the token type (i.e. its code) and *value* its actual
    value in the code.
    '''
    res = [[]]
    for token_values in tokens:
        if (token, value) == token_values[:2]:
            res.append([])
            continue
        res[-1].append(token_values)
    return res
"""
code_sample2 ='''
def factorial(n):
    if n < 2: return 1
    return n * factorial(n - 1)

def foo(bar):
    return sum(i for i in range(bar ** 2) if bar % i)

def SORT(arr: list):
    n = len(arr)

    for i in range(n):
        for j in range(0, n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
    return arr
'''
stat_analysis = analyze(code_sample1)
v = ComplexityVisitor.from_code(code_sample2)

print("Analysis:\n",stat_analysis,"\n")

allfunc=v.functions
print(allfunc)
print("\nFUNC\tCYCLO_COMPLEXITY")
for f in allfunc:
    print(f[0]," ",f[-1])

# [Function(name='factorial', lineno=2, col_offset=0, endline=4, is_method=False,
#           classname=None, closures=[], complexity=2),
#  Function(name='foo', lineno=6, col_offset=0, endline=7, is_method=False, classname=None,
#           closures=[], complexity=3)]
