class Solution
{
public:
	long int findmincoins(vector<int> &coins, int i, int amt, long int sum, vector<vector< long int>> &dp)
	{
		if (sum == amt)
			return 0;
		if (i == coins.size() || amt < 0)
			return INT_MAX;
		if (dp[i][sum] != -1)
			return dp[i][sum];
		if (coins[i] + sum <= amt)
		{
			dp[i][sum] = min(findmincoins(coins, i, amt, sum + coins[i], dp) + 1, findmincoins(coins, i + 1, amt, sum, dp));
		}
		else
			dp[i][sum] = findmincoins(coins, i + 1, amt, sum, dp);
		return dp[i][sum];
	}

	long int coinChange(vector<int> &coins, int amount)
	{
		int n = coins.size();
		vector<vector < long int>> dp(coins.size() + 1, vector < long int > (amount + 1, -1));

		int ans = findmincoins(coins, 0, amount, 0, dp);
		if (ans == INT_MAX)
			return -1;
		else
			return ans;

	}
};
