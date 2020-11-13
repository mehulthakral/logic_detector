class Solution:
    def numTrees(self, n: int) -> int:
        # Intuition:
        #   - For each n we try to build BST with node i from 1 -> n as root node
        #   - If n = 0 or 1 then only 1 way to form a BST tree
        #   - For each i we have i - 1 nodes on left subtree and n - i nodes on right subtree
        #   - The result is sum of all BST above. 
        #       G(n) = f(1, n) + f(2, n) + ... + f(n, n)
        #   - For each BST tree above we calculate number of left subtree * number of right subtree. We can see the sub problem here
        #       f(i, n) = G(i - 1) * G(n - i)
        #   - Final formula:
        #       G(n) = G(0) * G(n - 1) + G(1) * G(n - 2) + ... + G(n - 1) * G(0)
        
        # There is only one way to form BST with 0 or 1 node
        if n <= 1:
            return 1
        
        # Build up solution from 0 to n
        dp = [0] * (n + 1)
        # We already know the result for input = 1, input = 2
        dp[0], dp[1] = 1, 1
        
        # Continue calculate result for input from 2 -> n
        for i in range(2, n + 1):
            # For each i calculate all possible structurally BSTs that can form by j as root node
            for j in range(1, i + 1):
                dp[i] += dp[j - 1] * dp[i - j]
            
        return dp[n]
        
        
