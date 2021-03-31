class Solution {
    public:
        vector<vector<int>> levelOrder(TreeNode* root) {
            vector<vector <int>> res;
            if(root==NULL) return res;
            helper(root, res, 0);
            return res;
        }
        
    private:
        int rows = 0;
        void helper(TreeNode* node, vector<vector<int>> &res, int count){
            if(node == NULL) return;
            if(count >= rows){
                vector<int> newRow;
                newRow.push_back(node->val);
                res.push_back(newRow);
                rows++;
            }
            else{
                res[count].push_back(node->val);
            }
            helper(node->left, res, count + 1);
            helper(node->right, res, count + 1);
            return; 
        }
    };