class Solution2:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        self.bt(board, 0 ,0)
        
    def bt(self, board, i, j):
        if i == 9: return True
        if j >=9: return self.bt(board, i+1, 0)
        if board[i][j] != '.':
            return self.bt(board, i, j+1)
        
        for k in range(1,10):
            if self.isValid(board, i, j, str(k)):
                board[i][j] = str(k)
                if self.bt(board, i, j+1):
                    return True
                board[i][j] = '.'

        return False
    
    def isValid(self, board, x, y, v):
        for i in range(9):
            if board[x][i] == v:
                return False
        for i in range(9):
            if board[i][y] == v:
                return False
        
        #top-left corner in subboxes
        nx = 3*(x//3)
        ny = 3*(y//3)
        for i in range(3):
            for j in range(3):
                if board[nx+i][ny+j] == v:
                    return False
        return True
