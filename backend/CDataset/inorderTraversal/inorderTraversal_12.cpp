class Solution {
public:
    #include<vector>
    class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
	vector<int> inorderTraversal(TreeNode* root)
	{
		vector<int> traversed_values;
		stack<TreeNode*> to_traverse;

		TreeNode* current = root;

		while (current != nullptr || !to_traverse.empty()) {
			if (current != nullptr) {
				to_traverse.push(current);
				current = current->left;
			}
			else {
				current = to_traverse.top();
				to_traverse.pop();
				traversed_values.push_back(current->val);
				current = current->right;
			}
		}
		return traversed_values;
	}
};
