class Solution {
    using vi = vector<int>;
    using vvi = vector<vi>;
public:
    int coinChange(vector<int>& coins, int amount) {
        vvi memo(coins.size(), vi(amount+1, -1));
        int res = cc_r(coins, memo, amount);
        return res < 1000 ? res : -1;
    }
    
    int cc_r(vi& coins, vvi& memo, int k, int idx=0) {
        if (k==0) return 0;
        if (k<0 || idx==coins.size())  return 1000;
        
        if (memo[idx][k] != -1) return memo[idx][k];
        
        return memo[idx][k] = min(1+cc_r(coins, memo, k-coins[idx], idx),
                               cc_r(coins, memo, k, idx+1));
    }  
};
