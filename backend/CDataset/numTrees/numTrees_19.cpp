class Solution {
public:
	int numTrees(int n) {
		if(n==0) return 1;
		if(n==1) return 1;
		if(n==2) return 2;
		vector<int> dp(n+1,0);
		dp[0]=1;
		dp[1]=1;
		dp[2]=2;
		for(int i=3;i<n+1;i++){
			for(int j=1;j<=i;j++){
				dp[i]+=dp[j-1]*dp[i-j];
			}
		}
		return dp[n];
	}
};