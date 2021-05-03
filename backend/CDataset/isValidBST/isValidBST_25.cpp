#define inf 1e12
class Solution {
public:
class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
    pair<bool,pair<long long,long long>> recursion(TreeNode* root){
        pair<bool,pair<long long,long long>> p,q;
        if(!root){
            p.first = true;
            p.second.first = -1 * inf;
            p.second.second = inf;
            return p;
        }
        
        if(root->left and root->left->val>=root->val){
            p.first = false;
            return p;
        }
        if(root->right and root->right->val<=root->val){
            p.first = false;
            return p;
        }
        p = recursion(root->left);
        q = recursion(root->right);
        if(p.first==false or q.first==false or root->val<=p.second.first or root->val>=q.second.second){
            p.first = false;
            return p;
        }
        p.first = true;
        p.second.first = max(max((long long)root->val,p.second.first),q.second.first);
        p.second.second = min(min((long long)root->val,p.second.second),q.second.second);
        return p;
    }
    bool isValidBST(TreeNode* root) {
        pair<bool,pair<int,int>> p = recursion(root);
        return p.first;
    }
};
