
from typing import List, Set, Dict, Tuple, Optional

def EQUAL(a:int,b:int):
    return a==b

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

def POW(x:float,n:int):
    return x**n

def GCD(x:int,y:int):
   while(y): 
       x, y = y, x % y 
  
   return x 

def STR_SEARCH(text:str,pattern:str):
    return pattern in text

def COUNT_ISLANDS(graph:List[List[int]]): 
    ROW=len(graph)
    COL=len(graph[0])

    visited = [[False for j in range(COL)]for i in range(ROW)] 
    count = 0

    def isSafe(i, j, visited): 
        return (i >= 0 and i < ROW and j >= 0 and j < COL and not visited[i][j] and graph[i][j]) 

    def DFS(i, j, visited): 
        rowNbr = [-1, -1, -1,  0, 0,  1, 1, 1]
        colNbr = [-1,  0,  1, -1, 1, -1, 0, 1]
        visited[i][j] = True
        for k in range(8): 
            if isSafe(i + rowNbr[k], j + colNbr[k], visited): 
                DFS(i + rowNbr[k], j + colNbr[k], visited) 

    for i in range(ROW): 
        for j in range(COL): 
            if visited[i][j] == False and graph[i][j] == 1: 
                DFS(i, j, visited) 
                count += 1

    return count 