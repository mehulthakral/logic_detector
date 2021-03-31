class Solution {
private:
    
    // Map sorts by key, maintains 
    // our levels in order
    map<int, vector<int>> ourLevels;
    
    void insertAtLevel(TreeNode* root, int level) {
        if (!root) return;
        // Visit each node once, add it to our map that
        // maps nodes to their levels in the tree
        ourLevels[level].push_back(root->val);
        insertAtLevel(root->left, level + 1);
        insertAtLevel(root->right, level + 1);
        return;
    }
    
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ourRes;
        insertAtLevel(root, 0);
        // Go over each level in our map
        for (const auto& key : ourLevels) {
        // Push the level into our result vector
            ourRes.push_back(key.second);
        }
        return ourRes;
    }
};