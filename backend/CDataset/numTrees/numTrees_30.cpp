class Solution {
public:
    int numTrees(int n) {
        if(n < 2) return 1;
        if(n == 2) return 2;
        int DP[n + 1];
        DP[0] = 1;
        DP[1] = 1;
        int sub_res = 0;
        for(int i = 2; i <= n; i++){
            sub_res = 0;
            for(int j = 1; j <= i; j++){
                sub_res += DP[i - j] * DP[j - 1];
            } 
            DP[i] = sub_res;
        }
        return DP[n];
    }
};