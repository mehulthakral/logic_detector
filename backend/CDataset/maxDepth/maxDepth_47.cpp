class Solution {
public:
int maxDepth(TreeNode* root) {
    //return solution1(root);   //DFS
    return solution2(root);     //BFS
}
private:
int solution1(TreeNode* root) {
    if(root == NULL) return 0;
    return 1 + max(solution1(root->left), solution1(root->right));
}
int solution2(TreeNode *root){
    if(root == NULL) return 0;
    queue<TreeNode *> que;
    que.push(root);
    int depth = 0, count;
    TreeNode *left, *right;
    while(que.empty() == false){
        depth++;
        count = que.size();
        for(int i = 0; i < count; i++){
            left = que.front()->left;
            if(left) que.push(left);
            right = que.front()->right;
            if(right) que.push(right);
            que.pop();
        }
    }
    return depth;
}
};