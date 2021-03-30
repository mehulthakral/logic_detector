class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		queue<TreeNode*> q;
		vector<vector<int>> output;
		if(root==NULL) return output;
		q.push(root);
		while(q.empty()==false){
			int nodeCount = q.size();
			vector<int> v;
			while(nodeCount>0){
				TreeNode* temp = q.front();
				v.push_back(temp->val);
				q.pop();
				if(temp->left!=NULL){
					q.push(temp->left);
				}
				if(temp->right!=NULL){
					q.push(temp->right);
				}
				nodeCount--;
			}
			output.push_back(v);
			v.clear();
		}
		return output;
	}
};