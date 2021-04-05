import os
import random
import importlib.machinery
import model1.predict as mp
import json
from typing import List
import collections, itertools
import model1.dataset as g1
import inspect

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# def test():
#     # print(os.listdir('.'))
#     labels = os.listdir('.')
#     labels.remove(os.path.basename(__file__))
#     # print(labels)
#     label = random.choice(labels)
#     # print(label)
#     prgs = os.listdir(label)
#     if '__pycache__' in prgs:
#         prgs.remove('__pycache__')
#     prg = random.choice(prgs)
#     # print(prg)
#     loader = importlib.machinery.SourceFileLoader(label, label+'/'+prg)
#     handle = loader.load_module(label)
#     s = handle.Solution()
#     return getattr(s, label)
#     # return s.label


def test():
    # print(os.listdir('.'))
    labels = os.listdir('dataset_working')
    # labels.remove(os.path.basename(__file__))
    # print(labels)
    label = random.choice(labels)
    # print(label)
    prgs = os.listdir('dataset_working'+'/'+label)
    if '__pycache__' in prgs:
        prgs.remove('__pycache__')
    prg = random.choice(prgs)
    # print(prg)
    loader = importlib.machinery.SourceFileLoader('dataset_working'+'/'+label, 'dataset_working'+'/'+label+'/'+prg)
    handle = loader.load_module('dataset_working'+'/'+label)
    s = handle.Solution()
    return getattr(s, label)
    # return s.label

f = None

class Adaptor:
    def __init__(self):
        pass
    
    def fib(self,n:int)->int:
        global f
        return f(n)

    def sortArray(self,l:list)->list:
        global f
        return f(l)

    def isPalindrome(self,n:int)->bool:
        global f
        return f(n)

    def myPow(self, x: float, n: int) -> float:
        global f
        return f(x,n)

    def makeList(self,l):
        head = None
        if(len(l)==0):
            return head
        else:
            head = temp = ListNode(l[0])
            for i in range(1,len(l)):
                temp.next = ListNode(l[i])
                temp = temp.next
        return head

    def makeListCycle(self,l,p):
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
    
    def breakList(self,head):
        l = []
        while(head!=None):
            l.append(head.val)
            head = head.next
        return l

    def makeTree(self,i:int,lt:List[int]):
        if(i>=len(lt)):
            return None
        root = TreeNode(lt[i])
        root.left = self.makeTree(2*i+1,lt)
        root.right = self.makeTree(2*i+2,lt)
        return root

    def canFinish(self,ip:List[List[int]]={"start":0,"end":1}):
        global f
        numCourses = len(ip)
        prerequisites = []
        for i in range(len(ip)):
            for j in range(len(ip)):
                if(ip[i][j]!=0):
                    prerequisites.append([i,j])
        return f(numCourses,prerequisites)

    def mySqrt(self,x:int={"start":0,"end":1000}):
        global f
        return f(x)

    def canJump(self,l:List[int]):
        global f
        return f(l)

    def coinChange(self,l:List[int],amount:int):
        global f
        return f(l,amount)

    def reverse(self,n:int):
        global f
        return f(n)

    def countPrimes(self,n:int={"start":0,"end":1000}):
        global f
        return f(n)

    def hasCycle(self,l:List[int],p:int):
        def makeListCycle(l,p):
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

        global f
        return f(makeListCycle(l,p))

    def reverseList(self,l:List[int]):
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

        global f
        return breakList(f(makeList(l)))

    def isAnagram(self,a:str={"upper_count":0,"lower_count":10,"digits_count":0,"special_count":0}, b:str={"upper_count":0,"lower_count":10,"digits_count":0,"special_count":0}):
        global f
        return f(a,b)

    def isUgly(self,n:int):
        global f
        return f(n)

    def numIslands(self,g:List[List[int]]):
        global f
        n = len(g)
        grid = [[str(g[i][j]) for j in range(n)] for i in range(n)]
        return f(grid)

    def numTrees(self,n:int):
        global f
        return f(n)

    def rotate(self,l:List[int],k:int):
        global f
        f(l,k)
        return l

    def strStr(self,a:str,b:str):
        global f
        return f(a,b)

    def solveSudoku(self,board:List[List[int]]={"generator":"""
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
        global f
        myBoard = [[str(board[i][j]) if board[i][j]!=0 else "." for j in range(len(board))] for i in range(len(board))]
        f(myBoard)
        return [[int(myBoard[i][j]) for j in range(len(board))] for i in range(len(board))]

    def inorderTraversal(self,l:List[int]):
        def makeTree(i:int,lt:List[int]):
            if(i>=len(lt)):
                return None
            root = TreeNode(lt[i])
            root.left = makeTree(2*i+1,lt)
            root.right = makeTree(2*i+2,lt)
            return root
        
        global f
        return f(makeTree(0,l))

    def isValidBST(self,l:List[int]):
        def makeTree(i:int,lt:List[int]):
            if(i>=len(lt)):
                return None
            root = TreeNode(lt[i])
            root.left = makeTree(2*i+1,lt)
            root.right = makeTree(2*i+2,lt)
            return root

        global f
        return f(makeTree(0,l))

    def levelOrder(self,l:List[int]):
        def makeTree(i:int,lt:List[int]):
            if(i>=len(lt)):
                return None
            root = TreeNode(lt[i])
            root.left = makeTree(2*i+1,lt)
            root.right = makeTree(2*i+2,lt)
            return root

        global f
        return f(makeTree(0,l))

    def maxDepth(self,l:List[int]):
        def makeTree(i:int,lt:List[int]):
            if(i>=len(lt)):
                return None
            root = TreeNode(lt[i])
            root.left = makeTree(2*i+1,lt)
            root.right = makeTree(2*i+2,lt)
            return root

        global f
        return f(makeTree(0,l))

    def maxPathSum(self,l:List[int]):
        def makeTree(i:int,lt:List[int]):
            if(i>=len(lt)):
                return None
            root = TreeNode(lt[i])
            root.left = makeTree(2*i+1,lt)
            root.right = makeTree(2*i+2,lt)
            return root

        global f
        return f(makeTree(0,l))

def evaluate():
    # labels = os.listdir('dataset_working')
    # # labels.remove(os.path.basename(__file__))
    # labels.remove('isAnagram')
    # labels.remove('myPow')
    # labels.remove('isPalindrome')
    # labels.remove('fib')
    

    map = json.load(open("mapping.json"))
    # labels = list(map.keys())-['fib','sortArray','isPalindrome','myPow','canFinish','restoreIPAddresses',"canJump",'countPrimes',"coinChange","mySqrt","countPrimes","reverse","rotate","isUgly","numTrees","hasCycle","reverseList","numIslands","canFinish","strStr","isAnagram","inorderTraversal","isValidBST","levelOrder","maxDepth","maxPathSum","solveSudoku",'isAnagram']
    labels = ["coinChange"]
    # print(map["canFinish"][0])
    total = 0
    correct = 0
    for label in labels:
        prgs = os.listdir('dataset'+'/'+label)
        prgs.sort()
        if '__pycache__' in prgs:
            prgs.remove('__pycache__')
        ltotal = 0
        lcorrect = 0
        for prg in prgs:
            total += 1
            ltotal += 1
            print("Evaluating " + prg)
            loader = importlib.machinery.SourceFileLoader('dataset'+'/'+label, 'dataset'+'/'+label+'/'+prg)
            handle = loader.load_module('dataset'+'/'+label)
            s = handle.Solution()
            a = Adaptor()
            global f
            f = getattr(s, label)
            res = mp.predict(getattr(a,label),"python")
            oplabel = res
            if(oplabel==map[label][0]):
                correct +=1
                lcorrect += 1
            print(res,label)
            print("Accuracy till "+ str(total)+" prgs: " + str((float(correct)/total)*100) )

        with open("results.txt",'a') as f:
            f.write("Accuracy of "+ label + " " + str(lcorrect)+"/"+str(ltotal)+" prgs: " + str((float(lcorrect)/ltotal)*100)+"\n")
    
    return  (float(correct)/total)*100

def add_prgs():

    map = json.load(open("mapping.json"))
    labels = ["solveSudoku"]
    # done = ["sortArray","rotate","fib","isPalindrome","myPow","isUgly",countPrimes","mySqrt","reverse","numTrees","isAnagram","strStr","canJump","coinChange","numIslands","canFinish","hasCycle","reverseList","inorderTraversal","isValidBST","maxDepth","maxPathSum","levelOrder"]
    for label in labels:
        prgs = os.listdir('dataset'+'/'+label)
        prgs.sort()
        if '__pycache__' in prgs:
            prgs.remove('__pycache__')

        for prg in prgs:
            fobj=open("random.json")
            data=fobj.read()
            obj=json.loads(data)
            fobj.close()
            if(prg in obj):
                continue

            print("Adding " + prg)
            loader = importlib.machinery.SourceFileLoader('dataset'+'/'+label, 'dataset'+'/'+label+'/'+prg)
            handle = loader.load_module('dataset'+'/'+label)
            s = handle.Solution()
            a = Adaptor()
            global f
            f = getattr(s, label)
            # res = mp.predict(getattr(a,label),"python")

            # func_source_str = inspect.getsource(getattr(a,label))
            # fobj=open("random.json","w")
            # func_source_str = func_source_str.replace("\n    ","\n")
            # func_source_str = func_source_str.replace("    def","def",1)
            # # print(func_source_str)
            # data=json.dumps(func_source_str,indent="\t")
            # fobj.write(data)
            # fobj.close()  

            fn_src = ""
            # f = 0
            for m in dir(s):
                if ((not m.startswith('__')) and (inspect.isfunction(getattr(s, m)) or (inspect.ismethod(getattr(s, m))))):
                    src = inspect.getsource(getattr(s, m))
                    # src = src.replace("\n    ","\n")
                    # src = src.replace("    def","def",1)
                    # print(src)
                    if(len(fn_src)==0):
                        # fn_src += "\t"
                        src = src.replace("    def","def",1)
 
                    # fn_src += src.replace("\n","\n\t")
                    fn_src += src
                    fn_src += '\n'
            # print(fn_src)
            g1.json_dataset.add((map[label][0],getattr(a,label),label,fn_src),"python")
            fobj=open("random.json","w")
            obj.append(prg)
            data=json.dumps(obj,indent="\t")
            fobj.write(data)
            fobj.close() 

    print("Programs added successfully!")

def optimize_evaluate():
    fobj=open("model1/Labelled.json")
    data=fobj.read()
    obj=json.loads(data)
    fobj.close()

    #del obj["MIN"]
    #del obj["MAX"]
    # print(obj.keys())
    overall_sum = 0.0
    for key in obj.keys():
        print(key, len(obj[key]))
        total, correct = 0,0
        for comb in obj[key]:
            total += 1
            found_value = [dictionary for dictionary in comb["Results"] if dictionary["Model_Rank"] == 1.0]
            if(len(found_value)>0):
                correct += 1
        with open("results.txt",'a') as f:
            f.write("Accuracy of "+ key + " " + str(correct)+"/"+str(total)+" combs: " + str((float(correct)/total)*100)+"\n")
        overall_sum += (float(correct)/total)*100
    with open("results.txt",'a') as f:
            f.write("Overall Accuracy: " + str(float(overall_sum)/len(obj))+"\n")

# print(test())
# print(evaluate())
# add_prgs()
optimize_evaluate()