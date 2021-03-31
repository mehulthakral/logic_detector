struct QNode{
    TreeNode *node;
    long long lower, upper;
};
class Solution {
public:
    bool isValidBST(TreeNode* root){
        if(!root) return true;
        queue<QNode> q;
        q.emplace(QNode{root, LONG_MIN, LONG_MAX});
        while(!q.empty()){
            QNode curr = q.front(); q.pop();
            TreeNode* node = curr.node;
            if(!node) continue;
            if(node->val<=curr.lower or node->val>=curr.upper) return false;
            q.emplace(QNode{node->left, curr.lower, node->val});
            q.emplace(QNode{node->right, node->val, curr.upper});
        }
        return true;
    }
};