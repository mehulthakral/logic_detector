class Solution {
public:
    int numTrees(int n) {
        if (n < 0) return 1;
        
        vector<int> bst(n+1, 0);
        int i = 0, j = 0;
        bst[0] = 1;
        
        for (i = 1; i <= n; ++i)
            for (j = 1; j <= i; ++j)
                bst[i] += (bst[j-1] * bst[i-j]);
                
        return bst[n];
    }
};