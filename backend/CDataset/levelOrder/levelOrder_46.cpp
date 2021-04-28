class Solution {
public:
    #include<vector>

    class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
vector<vector<int>> levelOrder(TreeNode* root) {
    queue<TreeNode*> que;
    vector<vector<int>> result;
    vector<int> tmp;
    if(!root) return result;
    TreeNode* nullPointer=NULL;
    que.push(root);
    que.push(nullPointer);
    while(!que.empty()){
        auto ptr=que.front();
        que.pop();
        if(ptr==NULL){
            result.push_back(tmp);
            tmp.clear();
            if(!que.empty()){
               que.push(nullPointer);
               continue;
            }
            else
                  break;
        }
        else
          tmp.push_back(ptr->val);
        if(ptr->left)
           que.push(ptr->left);
        if(ptr->right)
           que.push(ptr->right);
    }
    return result;
    
}
};