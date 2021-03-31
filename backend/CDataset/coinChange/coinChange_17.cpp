class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> memo(amount + 1, amount + 1);
        memo[0] = 0;
        for (int amt = 1; amt <= amount; amt++)
        {
            for (int coin : coins)
            {
                // If this coin can be used to make amt
                if (coin <= amt)
                {
                    // Number of coins required to make amt amount is
                    // Minimum of (current minimum number of coins required to make amt) and
                    //            (Sum of Current coin value and minimum number of coins
                    //               required for (amt - coin val) amount)
                    memo[amt] = min(memo[amt], memo[amt - coin] + 1);
                }
            }
        }
        // Return memo of amount if making that amount with given coins is possible.
        // Otherwise, return -1
        return memo[amount] > amount ? -1 : memo[amount];
    }
};
