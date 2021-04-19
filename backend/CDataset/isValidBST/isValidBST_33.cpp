class Solution {
public:	class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
    struct Tuple{
        TreeNode* node;
        long long l, h;
        Tuple(TreeNode* node, long long l, long long h): node(node), l(l), h(h){}
    };
    
    bool isValidBST(TreeNode* root) {
        queue<Tuple*> q;
        q.push(new Tuple(root, numeric_limits<long long>::min(), numeric_limits<long long>::max()));
        while(!q.empty()){
            Tuple* curr = q.front();
            q.pop();
            if(curr->node == nullptr) continue;
            if(curr->node->val <= curr->l || curr->node->val >= curr->h) return false;
            q.push(new Tuple(curr->node->left, curr->l, curr->node->val));
            q.push(new Tuple(curr->node->right, curr->node->val, curr->h));
        }
        return true;
    }
};