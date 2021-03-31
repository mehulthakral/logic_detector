class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
		if (amount == 0) return 0;
		vector<double> result(amount + 1, amount + 1);
		result[0] = 0;
		for (int i = 1; i <= amount; i++)
		{
			for (int j = 0; j < coins.size(); j++)
			{
				if (i >= coins[j] && result[i] - 1 > result[i - coins[j]])
				{
					result[i] = result[i - coins[j]] + 1;
				}
			}
		}
		return (int)result[amount] > amount ? -1 : (int)result[amount];
	}
};
