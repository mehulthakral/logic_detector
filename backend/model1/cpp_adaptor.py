import cppyy
import cppyy.ll
import ctypes
from typing import List

class Adaptor:
    #Tested
    def isValidBST(self, arr:list):
        def newNode(val,left,right):
            #TODO Change malloc size
            node = cppyy.bind_object(cppyy.gbl.malloc(24), cppyy.gbl.Solution.TreeNode)
            node.left=left
            node.right=right 
            node.val=val 
            return node
        
        def makeTree(i:int,lt:list):
            if(i>=len(lt)):
                return cppyy.nullptr
            root = newNode(lt[i],makeTree(2*i+1,lt),makeTree(2*i+2,lt))
            return root
            
        tree=makeTree(0,arr)    
        obj=cppyy.gbl.Solution()
        return obj.isValidBST(tree)
    
    #Tested
    def canFinish(self, ip:List[List[int]]={"start":0,"end":1}):
        prerequisites = []
        for i in range(len(ip)):
            for j in range(len(ip)):
                if(ip[i][j]!=0):
                    prerequisites.append([i,j])
        new_vec = cppyy.gbl.std.vector(cppyy.gbl.std.vector(int))(len(prerequisites))
        for i in range(len(prerequisites)):
            vec=cppyy.gbl.std.vector(int)(len(prerequisites[i]))
            for j in range(len(prerequisites[i])):
                vec[j] = prerequisites[i][j]
            new_vec[i]=vec
        obj=cppyy.gbl.Solution()
        return obj.canFinish(len(ip),new_vec)
    
    #Tested
    def canJump(self, arr:list):
        new_vec = cppyy.gbl.std.vector(int)(len(arr))
        for i in range(len(arr)):
            new_vec[i] = arr[i]
        obj=cppyy.gbl.Solution()
        return obj.canJump(new_vec)
    
    #Tested
    def coinChange(self, arr:list, num:int):
        new_vec = cppyy.gbl.std.vector(int)(len(arr))
        for i in range(len(arr)):
            new_vec[i] = arr[i]
        obj=cppyy.gbl.Solution()
        return obj.coinChange(new_vec,num)

    #Tested
    def countPrimes(self,num:int={"start":0,"end":1000}):
        obj=cppyy.gbl.Solution()
        return obj.countPrimes(num)
    
    #Tested
    def fib(self,num:int):
        obj=cppyy.gbl.Solution()
        return obj.fib(num)
    
    #Tested
    def hasCycle(self,l:List[int],p:int):
        def makeList(l,p):
            head = None
            reqp = None
            if(len(l)==0):
                return head
            else:
                head = temp = newNode(l[0])
                for i in range(1,len(l)):
                    temp.next = newNode(l[i])
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
            
        def newNode(val):
            #TODO Change malloc size
            node = cppyy.bind_object(cppyy.gbl.malloc(24), cppyy.gbl.Solution.ListNode)
            node.next=cppyy.nullptr
            node.val=val 
            return node
            
        lst=makeList(l,p)    
        obj=cppyy.gbl.Solution()
        return obj.hasCycle(lst)
    
    #Tested
    def inorderTraversal(self, arr:list):
        def newNode(val,left,right):
            #TODO Change malloc size
            node = cppyy.bind_object(cppyy.gbl.malloc(24), cppyy.gbl.Solution.TreeNode)
            node.left=left
            node.right=right 
            node.val=val 
            return node
        
        def makeTree(i:int,lt:list):
            if(i>=len(lt)):
                return cppyy.nullptr
            root = newNode(lt[i],makeTree(2*i+1,lt),makeTree(2*i+2,lt))
            return root
            
        tree=makeTree(0,arr)    
        obj=cppyy.gbl.Solution()
        return obj.inorderTraversal(tree)

    #Tested
    def isAnagram(self,s:str={"upper_count":0,"lower_count":10,"digits_count":0,"special_count":0},t:str={"upper_count":0,"lower_count":10,"digits_count":0,"special_count":0}):
        obj=cppyy.gbl.Solution()
        return obj.isAnagram(s,t)
    
    #Tested
    def isPalindrome(self,num:int):
        obj=cppyy.gbl.Solution()
        return obj.isPalindrome(num)

    #Tested
    def isUgly(self,num:int):
        obj=cppyy.gbl.Solution()
        return obj.isUgly(num)

    #Tested
    def levelOrder(self, arr:list):
        def newNode(val,left,right):
            #TODO Change malloc size
            node = cppyy.bind_object(cppyy.gbl.malloc(24), cppyy.gbl.Solution.TreeNode)
            node.left=left
            node.right=right 
            node.val=val 
            return node
        
        def makeTree(i:int,lt:list):
            if(i>=len(lt)):
                return cppyy.nullptr
            root = newNode(lt[i],makeTree(2*i+1,lt),makeTree(2*i+2,lt))
            return root
            
        tree=makeTree(0,arr)    
        obj=cppyy.gbl.Solution()
        new_vec = obj.levelOrder(tree)
        new_list = []
        for i in new_vec:
            l=[]
            for j in i:
                l.append(j)
            new_list.append(l)
        return new_list
    
    #Tested
    def maxDepth(self,arr:list):
        def newNode(val,left,right):
            #TODO Change malloc size
            node = cppyy.bind_object(cppyy.gbl.malloc(24), cppyy.gbl.Solution.TreeNode)
            node.left=left
            node.right=right 
            node.val=val 
            return node
        
        def makeTree(i:int,lt:list):
            if(i>=len(lt)):
                return cppyy.nullptr
            root = newNode(lt[i],makeTree(2*i+1,lt),makeTree(2*i+2,lt))
            return root
            
        tree=makeTree(0,arr)    
        obj=cppyy.gbl.Solution()
        return obj.maxDepth(tree)
    
    #Tested
    def maxPathSum(self,arr:list):
        def newNode(val,left,right):
            #TODO Change malloc size
            node = cppyy.bind_object(cppyy.gbl.malloc(24), cppyy.gbl.Solution.TreeNode)
            node.left=left
            node.right=right 
            node.val=val 
            return node
        
        def makeTree(i:int,lt:list):
            if(i>=len(lt)):
                return cppyy.nullptr
            root = newNode(lt[i],makeTree(2*i+1,lt),makeTree(2*i+2,lt))
            return root
            
        tree=makeTree(0,arr)    
        obj=cppyy.gbl.Solution()
        return obj.maxPathSum(tree)

    #Tested
    def myPow(self,x:float,n:int):
        obj=cppyy.gbl.Solution()
        return obj.myPow(x,n)

    #Tested
    def mySqrt(self,n:int={"start":0,"end":1000}):
        obj=cppyy.gbl.Solution()
        return obj.mySqrt(n)

    #Tested
    def numIslands(self,g:List[List[int]]):
        n = len(g)
        l = [[str(g[i][j]) for j in range(n)] for i in range(n)]
        new_vec = cppyy.gbl.std.vector(cppyy.gbl.std.vector("char"))(len(l))
        for i in range(len(l)):
            vec=cppyy.gbl.std.vector("char")(len(l[i]))
            for j in range(len(l[i])):
                vec[j] = ord(l[i][j])
            new_vec[i]=vec
        obj=cppyy.gbl.Solution()
        return obj.numIslands(new_vec)

    #Tested
    def numTrees(self,n:int):
        obj=cppyy.gbl.Solution()
        return obj.numTrees(n)

    #Tested
    def reverse(self,n:int):
        obj=cppyy.gbl.Solution()
        return obj.reverse(n)

    #Tested
    def reverseList(self,l:list):
        def newNode(val,next):
            #TODO Change malloc size
            node = cppyy.bind_object(cppyy.gbl.malloc(24), cppyy.gbl.Solution.ListNode)
            node.next=next
            node.val=val 
            return node
        
        def makeList(i:int,lt:list):
            if(i>=len(lt)):
                return cppyy.nullptr
            root = newNode(lt[i],makeList(i+1,lt))
            return root

        def breakList(head):
            l = []
            while(head):
                l.append(head.val)
                head = head.next
            return l    
        lst=makeList(0,l)    
        obj=cppyy.gbl.Solution()
        return breakList(obj.reverseList(lst))
    
    #Tested
    def rotate(self, arr:list, n:int):
        new_vec = cppyy.gbl.std.vector(int)(len(arr))
        for i in range(len(arr)):
            new_vec[i] = arr[i]
        obj=cppyy.gbl.Solution()
        obj.rotate(new_vec,n)
        return new_vec
    
    #Tested
    def solveSudoku(self, board:List[List[int]]={"generator":"""
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
        myBoard = [[str(board[i][j]) if board[i][j]!=0 else "." for j in range(len(board))] for i in range(len(board))]
        new_vec = cppyy.gbl.std.vector(cppyy.gbl.std.vector("char"))(len(myBoard))
        for i in range(len(myBoard)):
            vec=cppyy.gbl.std.vector("char")(len(myBoard[i]))
            for j in range(len(myBoard[i])):
                vec[j] = ord(myBoard[i][j])
            new_vec[i]=vec
        obj=cppyy.gbl.Solution()
        obj.solveSudoku(new_vec)
        new_list = []
        for i in new_vec:
            l=[]
            for j in i:
                l.append(j)
            new_list.append(l)
        return [[int(new_list[i][j]) for j in range(len(board))] for i in range(len(board))]
    
    #Tested
    def sortArray(self, arr:list):
        new_vec = cppyy.gbl.std.vector(int)(len(arr))
        for i in range(len(arr)):
            new_vec[i] = arr[i]
        obj=cppyy.gbl.Solution()
        return obj.sortArray(new_vec)
    
    #Tested
    def strStr(self,s1:str={"upper_count":0,"lower_count":5,"digits_count":0,"special_count":0},s2:str={"upper_count":0,"lower_count":5,"digits_count":0,"special_count":0}):
        obj=cppyy.gbl.Solution()
        return obj.strStr(s1,s2)

if __name__=="__main__":
    Adaptor.generate()