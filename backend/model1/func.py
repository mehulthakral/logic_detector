
from typing import List, Set, Dict, Tuple, Optional

def EQUAL(a,b):
    return int(a==b)

def MAX(l:list):
    return max(l)

def MIN(l:list):
    return min(l)

def SUM(l:list):
    return sum(l)

def SEARCH(l:List[int],a:int):
    return a in l

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

def SORT(l:list):
    return sorted(l)

def FIB(N: int):
    if N < 2: return N
    a, b = 0, 1
    for _ in range(N-1):
        c = a+b
        a, b = b, c
    return c

def PALIN(x:int):
    return str(x) == str(x)[::-1] 

def POW(x:float,n:float):
    return x**n

def GCD(x:int,y:int):
   while(y): 
       x, y = y, x % y 
  
   return x 