class Solution {
public:
	int dp[31];
	int getResult(int n)
	{
		if(n <= 0)
			return 0;
		if(dp[n] != 0)
			return dp[n];
		dp[n] = getResult(n-1) + getResult(n-2);
		return dp[n];
	}
	int fib(int N) {

		memset(dp, 0, sizeof(dp));
		dp[1] = 1;
		return getResult(N);
	}
};