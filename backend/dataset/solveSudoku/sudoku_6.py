class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        spots = [] #empty spots
        row = [set() for _ in range(9)]
        col = [set() for _ in range(9)]
        sub = [set() for _ in range(9)]
        
        for i in range(9):
            for j in range(9):
                if board[i][j] == ".": spots.append((i, j))
                else: 
                    row[i].add(board[i][j])
                    col[j].add(board[i][j])
                    sub[i//3*3+j//3].add(board[i][j])
                    
        def fn(k):
            """return True if kth spot is filled properly"""
            if k == len(spots): return True
            i, j = spots[k]
            for n in map(str, range(1, 10)): 
                if n not in row[i] and n not in col[j] and n not in sub[i//3*3+j//3]: 
                    board[i][j] = n
                    row[i].add(n)
                    col[j].add(n)
                    sub[i//3*3+j//3].add(n)
                    if fn(k+1): return True
                    else:
                        row[i].remove(n)
                        col[j].remove(n)
                        sub[i//3*3+j//3].remove(n)
            return False 
        
        fn(0) #change in place 
