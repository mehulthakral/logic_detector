#pragma GCC optimize ("Ofast")
static auto _ = [] { std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0); std::cerr.tie(0); return 0; } ();

class Solution {
public:
    int helper(TreeNode* root, int &maxsum) {
        if(!root) return 0;
        int l = helper(root->left, maxsum);
        int r = helper(root->right, maxsum);
        
        if(l<0) l=0;
        if(r<0) r=0;
        
        if (l + root->val + r >maxsum) 
            maxsum = l + root->val + r;
        
        if (l>r) return root->val + l;
        else return root->val + r;
    }
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        int maxsum = root->val;
        helper(root, maxsum);
        return maxsum;
    }
};