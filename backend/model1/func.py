
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

def ANAGRAM(s:str,t:str):
      char_count = {}
      for char in s: char_count[char] = char_count.get(char, 0) + 1
      for char in t: char_count[char] = char_count.get(char, 0) - 1
      return False not in [char_count[char] == 0 for char in char_count]

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
    from collections import defaultdict
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

def SUDOKU(board={"generator":"""
def make_board():
    m=3
    import random
    n = m**2
    board = [[None for _ in range(n)] for _ in range(n)]

    def search(c=0):
        i, j = divmod(c, n)
        i0, j0 = i - i % m, j - j % m 
        numbers = list(range(1, n + 1))
        random.shuffle(numbers)
        for x in numbers:
            if (x not in board[i]                     
                and all(row[j] != x for row in board) 
                and all(x not in row[j0:j0+m]       
                        for row in board[i0:i])): 
                board[i][j] = x
                if c + 1 >= n**2 or search(c + 1):
                    return board
        else:
            board[i][j] = None
            return None

    x=search()
    number_of_dots=random.randint(5,15)
    for i in range(len(x)):
        for j in range(len(x[0])):
            if random.randint(0,1)==0 and number_of_dots>0:
                x[i][j]="."
                number_of_dots-=1
            else:
                x[i][j]=str(x[i][j])
    return x """}):
    dim = 9
    horizontal = [set() for _ in range(dim)]
    vertical = [set() for _ in range(dim)]
    grid = [[set() for _ in range(3)] for _ in range(3)]
    
    for i in range(dim):
        for j in range(dim):
            curr = board[i][j]
            if not curr == ".":
                curr = int(curr)
                horizontal[i].add(curr)
                vertical[j].add(curr)
                grid[i // 3][j // 3].add(curr)
    
    def search():
        for i in range(dim):
            for j in range(dim):
                curr = board[i][j]
                if curr == ".":
                    possible_set = set([k for k in range(1, dim + 1)])
                    possible_set -= horizontal[i]
                    possible_set -= vertical[j]
                    possible_set -= grid[i // 3][j // 3]
                    if len(possible_set) == 0: 
                        return False
                    for potential in possible_set:
                        board[i][j] = str(potential)
                        horizontal[i].add(potential)
                        vertical[j].add(potential)
                        grid[i // 3][j // 3].add(potential)
                        valid = search()
                        if valid:
                            return True
                        else:
                            board[i][j] = "."
                            horizontal[i].remove(potential)
                            vertical[j].remove(potential)
                            grid[i // 3][j // 3].remove(potential)
                    return False
        return True
    search()
    return board