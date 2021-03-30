int numTrees(int n) {
        // let C[i] be the number of unique binary search trees with 1 to i
        vector<int> C(n+1,1);
        
        for (int i = 2; i <= n; ++i) {
            C[i] = 0;
            for (int j = 1; j <= i; ++j) {
                C[i] += C[j-1] * C[i-j];
            }
        }
        return C[n];
    }