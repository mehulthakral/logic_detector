class Solution {
public:
    class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };

vector<vector> levelOrder(TreeNode* root) {
TreeNode* temp;
vector<vector> ans;
if(root==NULL)
return ans;
queue<TreeNode*> q;
q.push(root);
while(q.empty()==false){
int count=q.size();
vector v;
for(int i=0;i<count;i++){
temp=q.front();
q.pop();
v.push_back(temp->val);
if(temp->left!=NULL)
q.push(temp->left);
if(temp->right!=NULL)
q.push(temp->right);
}
ans.push_back(v);
}
return ans;
}
};