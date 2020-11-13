
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

def CATALAN_NUM(n:int):
    dp = {}
    dp[0] = 1
    for num in range(1, n + 1):
        res = 0
        for i in range(1, num + 1): 
            res = res + dp[i - 1] * dp[num - i]
        dp[num] = res
    return dp[n]

def UGLY_NUM(num:int):
    if num < 1: return False
    for factor in [2,3,5]:
        while num % factor == 0:
            num //= factor
    return num == 1

def CYCLE_DETECT(ip:List[List[int]]):
    numCourses = len(ip)
    prerequisites = []
    for i in range(len(ip)):
        for j in range(len(ip)):
            if(ip[i][j]!=0):
                prerequisites.append([i,j])
    in_degrees = [0 for x in range(numCourses)]
    start_nodes = []
    adj_matrix = defaultdict(list)
    for edge in prerequisites:
        if edge[0] == edge[1]:
            return False
        in_degrees[edge[1]] += 1
        adj_matrix[edge[0]].append(edge[1])
    
    for course_id, in_degree in enumerate(in_degrees):
        if in_degree == 0:
            start_nodes.append(course_id)
    
    if len(start_nodes) == 0:
        return False
    
    # bfs 
    visited = set() 
    for start_node in start_nodes:
        queue = [start_node]
        while queue:
            current = queue.pop()
            visited.add(current)
            for child in adj_matrix[current]:
                if child in visited:
                    continue
                in_degrees[child] -= 1
                if in_degrees[child] < 1:
                    queue.append(child)
    return len(visited) == numCourses     