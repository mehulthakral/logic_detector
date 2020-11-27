class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        # get a list of (row, col) of empty cells
        def get_vacant_positions(board):
            res = []
            for i in range(9):
                for j in range(9):
                    if board[i][j] == '.':
                        res.append((i, j))
            return res
        
        # get valid candidates that can be filled at (row, col)
        def get_candidates(board, row, col):
            res = set()
            for i in range(1, 10):
                res.add(str(i))
              
            # check row and col
            for i in range(9):
                if board[row][i] in res:
                    res.remove(board[row][i])
                if board[i][col] in res:
                    res.remove(board[i][col])
            
            # check box
            sr = (row // 3) * 3
            sc = (col // 3) * 3
            for i in range(sr, sr+3):
                for j in range(sc, sc+3):
                    if board[i][j] in res:
                        res.remove(board[i][j])
            
            return list(res)
        
        # fill using backtracking
        def solve(board, pos):
            if len(pos) == 0: # no more vacant positions to fill
                return True
            
            r, c = pos[0]
            candidates = get_candidates(board, r, c)
            
            if len(candidates) == 0: # no candidates, reject this path, backtrack
                return False
            
            for num in candidates:
                board[r][c] = num
                if solve(board, pos[1:]):
                    return True
                board[r][c] = '.'
            
            return False

        positions = get_vacant_positions(board)
        solve(board, positions)
