import cppyy

cppyy.cppdef("""
class Solution {
public:
    struct TreeNode
    {
        TreeNode* left;
        TreeNode* right;
        int val;
    };
     bool helper(TreeNode* root , long long minV = -10000000000,long long maxV = 10000000000)
    {
        if(root == NULL) return true;
        bool left = helper(root->left,minV,root->val);
        bool right = helper(root->right,root->val,maxV);
        
        if(left && right && root->val < maxV && root->val >minV)
        {
            return true;
        }
        else{
            return false;
        }
    }
    bool isValidBST(TreeNode* root) {
        return helper(root);
        
    }
};
""")

def adaptor(arr:list):
    
    def newNode(val,left,right):
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

from predict import predict 

print(predict(adaptor))

