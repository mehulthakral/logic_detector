
def EQUAL(a,b):
    return int(a==b)

def MIN(a,b):
    return min(a,b)

def MAX(a,b):
    return max(a,b)

def SUM(a,b):
    return a+b

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

def MAX_FREQ(a:list):
    d={}
    for i in a:
        if i not in d:
            d[i]=0 
        d[i]+=1
    m=0
    m_=0
    for i in d:
        if d[i]>m:
            m=d[i]
            m_=i
    return m_



#func=MAX