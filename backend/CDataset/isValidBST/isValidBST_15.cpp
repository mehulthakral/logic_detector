class Solution {
public:
class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
	bool isValidBST(TreeNode* root)
	{
		return inorder_evaluation(root);
	}
private:
	bool inorder_evaluation(TreeNode* current)
	{
		stack<TreeNode*> traversalStack;
        //long to accomodate lowest integer value
		long nodeValue = LONG_MIN;

		while (current != nullptr || !traversalStack.empty()) {
			if (current != nullptr) {
				traversalStack.push(current);
				current = current->left;
			}
			else {
				current = traversalStack.top();
				traversalStack.pop();
				//process the current node value
                if (nodeValue < current->val){
                    nodeValue = current->val;
                }
                else{
                    return false;
                }
				current = current->right;
			}
		}
		return true;
	}
	
};
