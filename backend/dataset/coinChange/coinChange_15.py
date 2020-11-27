class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        
        self.ans = float('inf')
		
		# Start searching from the biggest coin
        coins.sort(reverse=True)
        self.dfs(coins, amount, 0)
        return -1 if self.ans == float('inf') else self.ans

    
    def dfs(self, coins, amount, prev_count):
        """
        Recursive DFS function to seach valid coins combination.
        First is to use greedy method find out a potential-best solution.
        Then start to search the second biggest coin with pruning when the coins number >= the potential-best solution.

        Args:
            coins: coins list from which we pick coins into combination
            amount: target amount 
            prev_count: number of coins picked before this round
        
        """
        # Set up stop condtion
        if len(coins) == 0:
            return		

        if amount % coins[0] == 0:
			# Update potential answer
            self.ans = min(self.ans, prev_count + amount // coins[0])
        else:
            for k in range(amount // coins[0], -1, -1):
				# Set up pruning condtion
                if prev_count + k >= self.ans: 
                    break
                self.dfs(coins[1:], amount - k * coins[0], prev_count + k)
