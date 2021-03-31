class Solution {
private:
	//vector to store values if any
    vector<int> result;
public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
		//do traversal only if the tree is not empty
        if( root )
        {
			//traverse left sub tree first
            inorderTraversal(root->left);
			
			//visit the root node
            result.push_back(root->val);
			
			//traverse right sub tree last
            inorderTraversal(root->right);
        }
		//return the result 
        return result;
    }
};
