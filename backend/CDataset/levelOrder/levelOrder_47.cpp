class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
       vector<vector<int>> res;
	   if(!root) return res;
	   queue<TreeNode*> cur;
	   queue<TreeNode*> next;
	   cur.push(root);
	   vector<int> items;
	   while(!cur.empty())
	   {
		   //遍历一层
		   items.clear();
		   queue<TreeNode*>().swap(next);
		   while(!cur.empty())
		   {
			   TreeNode *tmp = cur.front();
			   cur.pop();
			   items.push_back(tmp->val);
			   if(tmp->left)  next.push(tmp->left);
			   if(tmp->right) next.push(tmp->right);
		   }
		   res.push_back(items);
		   //迭代
		   cur.swap(next);
	   }
	  

	   return res;

    }
	
};
