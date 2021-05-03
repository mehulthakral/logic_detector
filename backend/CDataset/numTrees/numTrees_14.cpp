class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1,0);
        dp[1] = 1;
        for(int i=2; i<=n;i++){
            // when n is leaf node or root node, count of such trees is dp[n-1]
            dp[i]+= 2*dp[i-1];

         // when n is intermediate node we have nodes on both sides of node n 
        // if there are x nodes above node n, no of trees which can be formed above =dp[x]
        // There will be n-1 - x nodes below node n 
        // no of trees which can be formed  below = dp[n-1-x]
    
        // we can select any permutation of the trees above and below
    //therefore total number of trees with node n as intermediate  =  dp[x] * dp[n-1-x]
            
            for(int j=1; j<i-1; j++)
                dp[i]+= dp[j]*dp[i-1-j];
         
        }
        return dp[n];
        
    }
};
