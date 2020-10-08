
def EQUAL(a,b,c):
    return int(a==b and b==c) 

def MIN(a,b,c):
    return min(a,b,c)

def MAX(a,b,c):
    return max(a,b,c)

def SUM(a,b,c):
    return a+b+c

def MAX_ARR(l:list):
    return max(l)

def MIN_ARR(l:list):
    return min(l)

def SUM_ARR(l:list):
    return sum(l)

def EQUAL_ARR(l:list):
    x=l[0]
    for i in l:
        if i!=x:
            return 0
    return 1

def SEARCH(l:list):
    for i in l:
        if i<0.5:
            return 1 
    return 0

def SQUARE(a:float):
    return a*a




#func=MAX