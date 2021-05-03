try:
    import c_mem_profile as mem
except:
    import model1.c_mem_profile as mem

def execute(func_str,func_name,parameter_list,input_data):
    time_taken=0
    mem_taken=0
    #print(func_name,parameter_list,input_data)
    func = getattr(Input_Adaptor,func_name)
    inp_data = func(input_data)
    func_str = """
#include <bits/stdc++.h>
#include <chrono>
using namespace std;
""" + func_str
    pre = Prerequisites(func_name)
    main = pre+"""
int main()
{
    auto start = chrono::high_resolution_clock::now();
  
    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);

    Solution MyObj;
"""+inp_data+"""    
    auto end = chrono::high_resolution_clock::now();
  
    // Calculating total time taken by the program.
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
  
    //time_taken *= 1e-9;
  
    cout << fixed << time_taken << setprecision(9);
    return 0;
}
    """
    func_str+=main
    #print(func_str)
    time_taken,mem_taken = mem.c_dynamic_metrics(func_str)
    #print(time_taken,mem_taken)
    return time_taken,mem_taken

def Prerequisites(func_name):
    Tree = ["inorderTraversal","isValidBST","levelOrder","maxDepth","maxPathSum"]
    List = ["hasCycle","reverseList"]
    string = ""
    if func_name in List:
        string = """
void insertFirst(Solution::ListNode *head, int val) {
   Solution::ListNode *link = (Solution::ListNode*) malloc(sizeof(Solution::ListNode));
   link->val = val;
   link->next = head;
   head = link;
}
        """
    elif func_name in Tree:
        string = """
Solution::TreeNode* newNode(int val, Solution::TreeNode* left, Solution::TreeNode* right)
{
    Solution::TreeNode* newNode = (Solution::TreeNode*) malloc(sizeof(Solution::TreeNode));
    if (!newNode) {
        cout << "Memory error";
        return NULL;
    }
    newNode->val = val;
    newNode->left = left;
    newNode->right = right;
    return newNode;
}

Solution::TreeNode* makeTree(int i, vector<int>& lt)
{
    if(i>lt.size())
        return NULL;
    Solution::TreeNode* root = newNode(lt[i],makeTree(2*i+1,lt),makeTree(2*i+2,lt));
    return root;
}
        """

    return string

class Input_Adaptor:
    def canFinish(input_data):
        num = "int inp1="+str(len(input_data[0]))+";\n"
        grid = "vector<vector<int>> inp2 {"
        c1=0 #counter for comma in {}
        for i in input_data[0]:
            s=""
            c=0
            for j in i:
                if c==0:
                    s=s+str(j)
                else:
                    s=s+","+str(j)
                c+=1
            if c1==0:
                grid=grid+"{"+s+"}"
            else:
                grid=grid+",{"+s+"}"
            c1+=1
        grid+="};\n"
        call = "MyObj.canFinish(inp1,inp2);"
        return num + grid + call

    def canJump(input_data):
        vec = "vector<int> inp1 {"
        c=0
        s=""
        for j in input_data[0]:
            if c==0:
                s=s+str(j)
            else:
                s=s+","+str(j)
            c+=1
        vec+=s
        vec+="};\n"
        call = "MyObj.canJump(inp1);"
        return vec + call
    
    def coinChange(input_data):
        vec = "vector<int> inp1 {"
        c=0
        s=""
        for j in input_data[0]:
            if c==0:
                s=s+str(j)
            else:
                s=s+","+str(j)
            c+=1
        vec+=s
        vec+="};\n"
        num = "int inp2="+str(input_data[1])+";\n"
        call = "MyObj.coinChange(inp1,inp2);"
        return vec + num + call
    
    def countPrimes(input_data):
        num = "int inp1="+str(input_data[0])+";\n"
        call = "MyObj.countPrimes(inp1);"
        return num + call

    def fib(input_data):
        num = "int inp1="+str(input_data[0])+";\n"
        call = "MyObj.fib(inp1);"
        return num + call
    
    #TODO Ask Mehul what the second number is for
    def hasCycle(input_data):
        num = "int inp1="+str(input_data[0])+";\n"
        call = "MyObj.hasCycle(inp1);"
        return num + call
    
    def inorderTraversal(input_data):
        vec = "vector<int> vec {"
        c=0
        s=""
        for j in input_data[0]:
            if c==0:
                s=s+str(j)
            else:
                s=s+","+str(j)
            c+=1
        vec+=s
        vec+="};\n"
        tree = "Solution::TreeNode* inp1 = makeTree(0,vec);\n"
        call = "MyObj.inorderTraversal(inp1);"
        return vec + tree + call
    
    def isAnagram(input_data):
        str1 = 'string inp1="'+str(input_data[0])+'";\n'
        str2 = 'string inp2="'+str(input_data[1])+'";\n'
        call = "MyObj.isAnagram(inp1,inp2);"
        return str1 + str2 + call
    
    def isPalindrome(input_data):
        num = "int inp1="+str(input_data[0])+";\n"
        call = "MyObj.isPalindrome(inp1);"
        return num + call
    
    def isUgly(input_data):
        num = "int inp1="+str(input_data[0])+";\n"
        call = "MyObj.isUgly(inp1);"
        return num + call
    
    def isValidBST(input_data):
        vec = "vector<int> vec {"
        c=0
        s=""
        for j in input_data[0]:
            if c==0:
                s=s+str(j)
            else:
                s=s+","+str(j)
            c+=1
        vec+=s
        vec+="};\n"
        tree = "Solution::TreeNode* inp1 = makeTree(0,vec);\n"
        call = "MyObj.isValidBST(inp1);"
        return vec + tree + call
    
    def levelOrder(input_data):
        vec = "vector<int> vec {"
        c=0
        s=""
        for j in input_data[0]:
            if c==0:
                s=s+str(j)
            else:
                s=s+","+str(j)
            c+=1
        vec+=s
        vec+="};\n"
        tree = "Solution::TreeNode* inp1 = makeTree(0,vec);\n"
        call = "MyObj.levelOrder(inp1);"
        return vec + tree + call
    
    def maxDepth(input_data):
        vec = "vector<int> vec {"
        c=0
        s=""
        for j in input_data[0]:
            if c==0:
                s=s+str(j)
            else:
                s=s+","+str(j)
            c+=1
        vec+=s
        vec+="};\n"
        tree = "Solution::TreeNode* inp1 = makeTree(0,vec);\n"
        call = "MyObj.maxDepth(inp1);"
        return vec + tree + call
    
    def maxPathSum(input_data):
        vec = "vector<int> vec {"
        c=0
        s=""
        for j in input_data[0]:
            if c==0:
                s=s+str(j)
            else:
                s=s+","+str(j)
            c+=1
        vec+=s
        vec+="};\n"
        tree = "Solution::TreeNode* inp1 = makeTree(0,vec);\n"
        call = "MyObj.maxPathSum(inp1);"
        return vec + tree + call
    
    def myPow(input_data):
        num1 = "double inp1="+str(input_data[0])+";\n"
        num2 = "int inp2="+str(input_data[1])+";\n"
        call = "MyObj.myPow(inp1,inp2);"
        return num1 + num2 + call
    
    def mySqrt(input_data):
        num = "int inp1="+str(input_data[0])+";\n"
        call = "MyObj.mySqrt(inp1);"
        return num + call

    def numIslands(input_data):
        grid = "vector<vector<char>> inp1 {"
        c1=0 #counter for comma in {}
        for i in input_data[0]:
            s=""
            c=0
            for j in i:
                if c==0:
                    s=s+str(j)
                else:
                    s=s+","+str(j)
                c+=1
            if c1==0:
                grid=grid+"{"+s+"}"
            else:
                grid=grid+",{"+s+"}"
            c1+=1
        grid+="};\n"
        call = "\nMyObj.numIslands(inp1);"
        return grid + call
    
    def numTrees(input_data):
        num = "int inp1="+str(input_data[0])+";\n"
        call = "MyObj.numTrees(inp1);"
        return num + call
    
    def restoreIpAddresses(input_data):
        str1 = 'string inp1="'+str(input_data[0])+'";\n'
        call = "MyObj.restoreIpAddresses(inp1);"
        return str1 + call
    
    def reverse(input_data):
        num = "int inp1="+str(input_data[0])+";\n"
        call = "MyObj.reverse(inp1);"
        return num + call
    
    def reverseList(input_data):
        init = "Solution::ListNode *head = NULL;\n"
        CList = ""
        input_data[0].reverse()
        for i in input_data[0]:
            CList=CList+"insertFirst(head,"+str(i)+");\n"
        call = "MyObj.reverseList(head);"
        return init + CList + call
    
    def rotate(input_data):
        vec = "vector<int> inp1 {"
        c=0
        s=""
        for j in input_data[0]:
            if c==0:
                s=s+str(j)
            else:
                s=s+","+str(j)
            c+=1
        vec+=s
        vec+="};\n"
        num = "int inp2="+str(input_data[1])+";\n"
        call = "MyObj.rotate(inp1,inp2);"
        return vec + num + call

    def solveSudoku(input_data):
        grid = "vector<vector<char>> inp1 {"
        c1=0 #counter for comma in {}
        for i in input_data[0]:
            s=""
            c=0
            for j in i:
                if c==0:
                    s=s+"'"+str(j)+"'"
                else:
                    s=s+",'"+str(j)+"'"
                c+=1
            if c1==0:
                grid=grid+"{"+s+"}"
            else:
                grid=grid+",{"+s+"}"
            c1+=1
        grid+="};\n"
        call = "\nMyObj.solveSudoku(inp1);"
        return grid + call
    
    def sortArray(input_data):
        vec = "vector<int> inp1 {"
        c=0
        s=""
        for j in input_data[0]:
            if c==0:
                s=s+str(j)
            else:
                s=s+","+str(j)
            c+=1
        vec+=s
        vec+="};\n"
        call = "MyObj.sortArray(inp1);"
        return vec + call
    
    def strStr(input_data):
        str1 = 'string inp1="'+str(input_data[0])+'";\n'
        str2 = 'string inp2="'+str(input_data[1])+'";\n'
        call = "MyObj.strStr(inp1,inp2);"
        return str1 + str2 + call