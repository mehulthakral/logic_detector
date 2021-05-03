class Solution {
public:class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int rez=0;
        queue <TreeNode *> q;
        q.push(root);
        
        while(!q.empty()){
          int i = q.size();                // put in i  number of nodes  on current row
        
          for(int j=0 ; j < i; j++){                //put in queue nodes for next row
            
              TreeNode *tmp = q.front();
              q.pop();
              if(tmp->left) q.push(tmp->left); 
              if(tmp->right) q.push(tmp->right);     
            
          }
        rez++;   // increase counter of rows
        }
    return rez;    
    }
};
