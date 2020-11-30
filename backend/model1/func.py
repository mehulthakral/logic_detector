
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

def JUMP_GAME(nums: list) -> bool:
  if nums[0] == 0 and len(nums) > 1:
    return False

  # maximum_dis stands for the maximum distance we can reach so far 
  maximum_dis = 0
  for i in range(len(nums)):
    # If the current index is beyond the maximum distance we can jump to, directly return False
    if i > maximum_dis:
      return False

    # If maximum_dis larger or equal to the last index, it means we can reach the last index for sure
    if maximum_dis >= len(nums) - 1:
      return True

    # Update the maximum_dis
    if nums[i] + i > maximum_dis:
      maximum_dis = nums[i] + i

def COIN_CHANGE(coins: list, amount: int) -> int:
  if not coins or amount <= 0:
    return 0

  f = [float('inf')] * (amount + 1)
  f[0] = 0
  for i in range(1, amount + 1):
    for c in coins:
      if i >= c:
        f[i] = min(f[i], f[i - c] + 1)
  return f[amount] if f[amount] != float('inf') else -1

def REVERSE_INTEGER(x: int) -> int:
                            minLimit = -2**31
                            maxLimit = 2**31
                            
                            numStr = str(x) #Conversion
                            numStr = numStr[::-1] #Reverse digits
                            
                            if numStr.endswith("-"):
                                numStr = "-" + numStr[:-1] #Remove "-" sign from the end and add it to the beginning

                            number = int(numStr)
                            if number not in range(minLimit,maxLimit): #Overflow
                                return 0
                            
                            return number

def ROTATE_ARRAY(nums: list, k: int) -> list:
                    def original(nums: list, k: int) -> None:
                        for _ in range(k):
                            nums.insert(0, nums.pop())
                    original(nums,k)
                    return nums

def REVERSE_LL(l:list)->list:
    class ListNode:
        def __init__(self, val=0, next=None):
            self.val = val
            self.next = next
    def makeList(l):
        head = None
        if(len(l)==0):
            return head
        else:
            head = temp = ListNode(l[0])
            for i in range(1,len(l)):
                temp.next = ListNode(l[i])
                temp = temp.next
        return head
    
    def breakList(head):
        l = []
        while(head!=None):
            l.append(head.val)
            head = head.next
        return l
        
    def original(head: ListNode) -> ListNode:
        if head is None or head.next is None :
            return head 
        if head.next is not None:
            last = None
            point = head

            while point is not None:
                point.next, point, last = last, point.next, point
                
            return last
    return breakList(original(makeList(l)))

def CYCLE_LL(l:list, p:int)->bool:
    class ListNode:
        def __init__(self, x):
            self.val = x
            self.next = None
    def makeList(l,p):
        head = None
        reqp = None
        if(len(l)==0):
            return head
        else:
            head = temp = ListNode(l[0])
            for i in range(1,len(l)):
                temp.next = ListNode(l[i])
                temp = temp.next
                if(i==p):
                    reqp = temp
        if(p==-1):
            return head
        if(reqp==None):
            temp.next = head
        else:
            temp.next = reqp
        return head
    
    def original(head: ListNode)->bool:
        if head == None or head.next == None:
            return False
        p = head
        q = head.next
        while q and q.next:
            if p == q:
                break
            p = p.next
            q = q.next.next
        if p != q:
            return False
        return True
    return original(makeList(l,p))

def INORDER_TRAVERSAL(lst: list) -> list:
    class TreeNode:
        def __init__(self, val=0, left=None, right=None):
            self.val = val
            self.left = left
            self.right = right

    def makeTree(i:int,lt:list):
        if(i>=len(lt)):
            return None
        root = TreeNode(lt[i])
        root.left = makeTree(2*i+1,lt)
        root.right = makeTree(2*i+2,lt)
        return root

    def original(root: TreeNode) -> list:
        if root is None:
            return []
        
        if root.left is None:
            l = []
        else:
            l = original(root.left)
            
        if root.right is None:
            r = []
        else:
            r = original(root.right)
            
        return l + [root.val] + r
    return original(makeTree(0,lst))

def VALID_BST(lst: list) -> bool:
    class TreeNode:
        def __init__(self, val=0, left=None, right=None):
            self.val = val
            self.left = left
            self.right = right

    def makeTree(i:int,lt:list):
        if(i>=len(lt)):
            return None
        root = TreeNode(lt[i])
        root.left = makeTree(2*i+1,lt)
        root.right = makeTree(2*i+2,lt)
        return root
    
    def original(root: TreeNode) -> bool:
        curr = root
        stack = []
        while(curr):
            stack.append(curr)
            curr = curr.left
        prev = None
        while(stack):
            top_ele = stack.pop()
            if prev is not None and top_ele.val <= prev:
                return False
            prev = top_ele.val
            next_right = top_ele.right
            while(next_right):
                stack.append(next_right)
                next_right = next_right.left
        return True
    return original(makeTree(0,lst))

def LEVELORDER_TRAVERSAL(l: list):
    class TreeNode:
        def __init__(self, val=0, left=None, right=None):
            self.val = val
            self.left = left
            self.right = right

    def makeTree(i:int,lt:list):
        if(i>=len(lt)):
            return None
        root = TreeNode(lt[i])
        root.left = makeTree(2*i+1,lt)
        root.right = makeTree(2*i+2,lt)
        return root
                            
    def original(root: TreeNode):
        sol = []
        def _solve(node, depth=0):
            if node:
                if depth >= len(sol):
                    sol.append([])
                _solve(node.left, depth+1)
                sol[depth].append(node.val)
                _solve(node.right, depth+1)
        _solve(root)
        return sol
    return original(makeTree(0,l))

def HEIGHT_BT(l: list):
    class TreeNode:
        def __init__(self, val=0, left=None, right=None):
            self.val = val
            self.left = left
            self.right = right

    def makeTree(i:int,lt:list):
        if(i>=len(lt)):
            return None
        root = TreeNode(lt[i])
        root.left = makeTree(2*i+1,lt)
        root.right = makeTree(2*i+2,lt)
        return root         
                            
    def original(root: TreeNode) -> int:
        if not root:
            return 0
        
        left = original(root.left)
        right = original(root.right)
        
        return max(left, right) + 1
    return original(makeTree(0,l))

def MAX_PATH_SUM_BT(l: list):
    class TreeNode:
        def __init__(self, val=0, left=None, right=None):
            self.val = val
            self.left = left
            self.right = right
    def makeTree(i:int,lt:list):
        if(i>=len(lt)):
            return None
        root = TreeNode(lt[i])
        root.left = makeTree(2*i+1,lt)
        root.right = makeTree(2*i+2,lt)
        return root         
                            
    def original(root: TreeNode) -> int:
        def check(node: TreeNode):
            (lps, ls) = check(node.left) if node.left else (0, float('-inf'))
            (rps, rs) = check(node.right) if node.right else (0, float('-inf'))
            return max(lps + node.val, rps + node.val, node.val), max(ls, rs, lps + node.val, rps + node.val, lps + rps + node.val, node.val)
        return check(root)[1]
    return original(makeTree(0,l))

def SQRT( x: int={"start":0,"end":1000}) -> int:
                        a = x            
                        while int(a) * int(a) > x:
                            a -= (a * a - x) / (2 * a)            
                        return int(a)

def SIEVE(n: int={"start":0,"end":1000}) -> int:
                                if n <= 2:
                                    return 0

                                table = [True]*n
                                table[0], table[1] = False,False

                                i = 2
                                while i*i < n:
                                    if table[i]:
                                        for j in range(i*i, n, i):
                                            table[j] = False
                                    i+=1

                                return sum(table)

def ANAGRAM(s:str={"upper_count":0,"lower_count":10,"digits_count":0,"special_count":0},t:str={"upper_count":0,"lower_count":10,"digits_count":0,"special_count":0}):
      char_count = {}
      for char in s: char_count[char] = char_count.get(char, 0) + 1
      for char in t: char_count[char] = char_count.get(char, 0) - 1
      return False not in [char_count[char] == 0 for char in char_count]