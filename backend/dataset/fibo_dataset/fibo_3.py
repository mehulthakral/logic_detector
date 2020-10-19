class Solution:
    def fib(self, n: int) -> int:
        
        def get_mat_mult(mat, other_mat):
            res = [[0 for _ in range(len(mat[0]))] for _ in range(len(mat))]
            for i in range(len(mat)):
                for j in range(len(mat[i])):
                    for k in range(len(other_mat[i])):
                        res[i][j] += mat[i][k] * other_mat[k][j]
            return res
        
        if n == 0 or n == 1:
            return n
        
        final_mat = [[1,0],[0,1]]
        start_mat = [[1,1], [1,0]]
        n -= 1
        while(n):
            if (n & 1):
                final_mat = get_mat_mult(start_mat, final_mat)
            start_mat = get_mat_mult(start_mat, start_mat) 
            n >>= 1
        return final_mat[0][0]
