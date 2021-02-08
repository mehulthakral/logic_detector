from radon.visitors import ComplexityVisitor
from radon.raw import analyze

def cyclomatic_complexity(fnc_str):
    v = ComplexityVisitor.from_code(fnc_str)
    allfunc = v.functions
    #print(allfunc)
    funcs={}
    for f in allfunc:
        funcs[f[0]]=f[-1]
        # print(f[0], " ", f[-1])
    return funcs

def other_metrics(fnc_str):
    stats = analyze(fnc_str)
    return stats

if __name__=="__main__":
    

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

    
    print(other_metrics(code_sample))
    print(cyclomatic_complexity(code_sample))


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
