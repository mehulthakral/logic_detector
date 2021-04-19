class Solution {
public:

    class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };

void bfs(TreeNode*root , vector<int>&v,vector<vector<int>>&qwer){
queue<TreeNode*>q;
if(root==NULL){
return;}

q.push(root);
q.push(NULL);

while(!q.empty()){
TreeNode*f=q.front();

if(f==NULL){
qwer.push_back(v);
    v.clear();
q.pop();
if(!q.empty()){
q.push(NULL);}}

else{
v.push_back(f->val);
q.pop();
 if(f->left){
q.push(f->left);}
if(f->right){
q.push(f->right);}}}
    return ;}
	
	
	vector<vector<int>> levelOrder(TreeNode* root) {
     vector<vector<int>>qwer;
    vector<int>v;
    bfs(root,v,qwer);
     return qwer;}
};
