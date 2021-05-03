class Solution {
public:
    class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };

	vector<vector<int>> levelOrder(TreeNode* root) {
		if(root == NULL) return {};

		queue<TreeNode*> q;
		vector<vector<int>> a;
		q.push(root);

		int n;

		while(!q.empty()){
			TreeNode * t;
			vector<int> temp;
			n = q.size();

			for(int i=0;i<n;i++){
				t = q.front();
				q.pop();
				temp.push_back(t->val);
				if(t->left) q.push(t->left);
				if(t->right) q.push(t->right);
			}
			a.push_back(temp);
		}

		return a;
	}
};