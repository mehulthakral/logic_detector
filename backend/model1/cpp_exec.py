"""import cppyy
from typing import List
f = open("../CDataset/canFinish/canFinish_1.cpp")

s = f.read()
cppyy.cppdef("using namespace std;")
cppyy.cppdef(s)
obj = cppyy.gbl.Solution()
obj.canFinish()

def adapter(num:int, vec:List[List[int]]):
    new_vec = cppyy.gbl.std.vector(cppyy.gbl.std.vector(int))(10)
    return obj.canFinish(num, vec)
"""

"""
f = open("../CDataset/isValidBST/isValidBST_1.cpp")

s = f.read()
cppyy.cppdef("using namespace std;")
cppyy.cppdef(s)
obj = cppyy.gbl.Solution()

def Adapter(num:List[int]):

    cppyy.cppdef("#include<stdlib.h>")
    cppyy.cppdef("Solution::TreeNode* node=(Solution::TreeNode*)malloc(24);
(*node).left=nullptr;
(*node).right=nullptr;
(*node).val=10;
    ")


    print(cppyy.gbl.size)
    node = cppyy.ll.malloc[int](cppyy.gbl.size)
    node.left = cppyy.nullptr
    node.right = cppyy.nullptr
    node.val= 10
    
    new_node = cppyy.ll.malloc[int](cppyy.gbl.size)
    new_node.left = cppyy.nullptr
    new_node.right = cppyy.nullptr
    new_node.val=15

    node.right = new_node
    
    node = cppyy.gbl.Solution.TreeNode()
    node.left = cppyy.nullptr
    node.right = cppyy.nullptr
    node.val=10

    new_node = cppyy.gbl.Solution.TreeNode()
    new_node.left = cppyy.nullptr
    new_node.right = cppyy.bind_object(cppyy.nullptr,cppyy.gbl.Solution.TreeNode)
    new_node.val=15
    
    
    return obj.isValidBST(cppyy.gbl.Node)
"""

import cppyy
import cppyy.ll
import ctypes
from typing import List
import predict as mp

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
    
    #Not working
    def canFinish(self, num:int, arr:List[List[int]]):
        prerequisites = []
        for i in range(len(arr)):
            for j in range(len(arr)):
                if(arr[i][j]!=0):
                    prerequisites.append([i,j])
                    #new_vec.push_back(cppyy.gbl.std.vector[int]([i,j]))

        new_vec = cppyy.gbl.std.vector(cppyy.gbl.std.vector(int))(len(prerequisites))

        for i in range(len(prerequisites)):
            new_vec[i]=cppyy.gbl.std.vector[int](prerequisites[i])
        print(new_vec,prerequisites)
        obj=cppyy.gbl.Solution()
        return obj.canFinish(num,new_vec)
    
    #Tested
    def canJump(self, arr:list):
        new_vec = cppyy.gbl.std.vector(int)(len(arr))
        for i in range(len(arr)):
            new_vec[i] = arr[i]
        obj=cppyy.gbl.Solution()
        return obj.canJump(new_vec)
    
    #Not working
    def coinChange(self, arr:list, num:int):
        new_vec = cppyy.gbl.std.vector(int)(len(arr))
        for i in range(len(arr)):
            new_vec[i] = arr[i]
        obj=cppyy.gbl.Solution()
        return obj.coinChange(new_vec,num)

    #Tested
    #Accuracy 0.0 giving Reverse_integer
    def countPrimes(self,num:int):
        obj=cppyy.gbl.Solution()
        return obj.countPrimes(num)
    
    #Tested
    def fib(self,num:int):
        obj=cppyy.gbl.Solution()
        return obj.fib(num)
    
    #Tested
    #Accuracy 0.0 giving VALID_BST 
    def hasCycle(self,l:list):
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
            
        lst=makeList(0,l)    
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
    #Accuracy 0.0 giving CYCLE_GRAPH 
    def isAnagram(self,s:str,t:str):
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

    #Not working
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
        return obj.levelOrder(tree)
    
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
    #Accuracy 0.0 giving UGLY_NUM 
    def mySqrt(self,n:int):
        obj=cppyy.gbl.Solution()
        return obj.mySqrt(n)

    #Not working
    def numIslands(self,l:List[List[str]]):
        new_vec = cppyy.gbl.std.vector(cppyy.gbl.std.vector(str))(len(l))

        for i in range(len(l)):
            l[i] = [str(j) for j in l[i]]
            new_vec[i]=cppyy.gbl.std.vector[str](l[i])
        print(new_vec,l)
        obj=cppyy.gbl.Solution()
        return obj.numIslands(new_vec)

    #Tested
    def numTrees(self,n:int):
        obj=cppyy.gbl.Solution()
        return obj.numTrees(n)

    #Not working
    def restoreIpAddresses(self,s:str):
        obj=cppyy.gbl.Solution()
        return obj.restoreIpAddresses(s)

    #Tested
    def reverse(self,n:int):
        obj=cppyy.gbl.Solution()
        return obj.reverse(n)

    #Not working
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
            
        lst=makeList(0,l)    
        obj=cppyy.gbl.Solution()
        return obj.reverseList(lst)
    
    #Not working
    def rotate(self, arr:list, n:int):
        new_vec = cppyy.gbl.std.vector(int)(len(arr))
        for i in range(len(arr)):
            new_vec[i] = arr[i]
        obj=cppyy.gbl.Solution()
        return obj.rotate(new_vec,n)
    
    #Not working
    def solveSudoku(self, arr:list):
        new_vec = cppyy.gbl.std.vector(int)(len(arr))
        for i in range(len(arr)):
            new_vec[i] = arr[i]
        obj=cppyy.gbl.Solution()
        return obj.solveSudoku(new_vec)
    
    #Tested
    def sortArray(self, arr:list):
        new_vec = cppyy.gbl.std.vector(int)(len(arr))
        for i in range(len(arr)):
            new_vec[i] = arr[i]
        obj=cppyy.gbl.Solution()
        return obj.sortArray(new_vec)
    
    #Tested
    #Accuracy 0.0 giving CYCLE_GRAPH 
    def strStr(self,s1:str,s2:str):
        obj=cppyy.gbl.Solution()
        return obj.strStr(s1,s2)

#print(predict(Adaptor))
def execute(func_str, label):
    cppyy.cppdef("using namespace std;")
    cppyy.cppdef(func_str)
    a = Adaptor()
    res = mp.predict(getattr(a,label),"C++")
    return res


import sys
handle = open(sys.argv[1])
label = sys.argv[2]
func_str = handle.read()
#print(func_str)
print(execute(func_str, label))
"""
f = open("../CDataset/isValidBST/isValidBST_1.cpp")

s = f.read()
cppyy.cppdef("using namespace std;")
cppyy.cppdef(s)
print(mp.predict(Adaptor.isValidBST))
"""