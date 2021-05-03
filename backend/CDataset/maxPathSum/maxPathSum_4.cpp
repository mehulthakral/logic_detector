class Solution {
public:
    class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
    int helper(TreeNode* root, int &rez){
      int leftval,rightval;
      bool l=false,r=false;
      if(!root->left && !root->right) {if(root->val > rez)rez=root->val;return root->val;}            // a)
      if(root->left) {                      //try to give result for left branch
        leftval = helper(root->left,rez);
        l = true;
      }
      if(root->right) {                    //try to give result for right branch
        rightval = helper(root->right,rez);
        r = true;
      }
      if(l && r){                             // d)
        int tmp = max(root->val,max(root->val + leftval,max(root->val + leftval + rightval,root->val  + rightval)));
        if(tmp > rez) rez = tmp;
        return max(root->val,max(root->val + leftval,root->val  + rightval));
      }else{
        if(l){                       // b)
          int tmp = max(root->val,root->val + leftval);
          if(tmp > rez) rez = tmp;
          return tmp;
        }                      // c)
        int tmp = max(root->val,root->val + rightval);
          if(tmp > rez) rez = tmp;
          return tmp;
      }
    }
  
    int maxPathSum(TreeNode* root) {
    int rez = INT_MIN;  
    if(root) helper(root, rez);  
    return rez;    
    }
};
