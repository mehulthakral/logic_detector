class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        def solve(r, c):
            if r == 9 and c == 9:
                return True
            if board[r][c] == '.':
                for num in range(1, 10):
                    if can_put(r, c, num):
                        board[r][c] = str(num)
                        res = solve(*getNext(r, c))
                        if res:
                            return True
                        else:
                            board[r][c] = '.'
            else:
                return solve(*getNext(r, c))

        
        def can_put(r, c, num):
            num = str(num)
            for i in range(len(board)):
                if board[i][c] == num:
                    return False
                
            for i in range(len(board[0])):
                if board[r][i] == num:
                    return False
                
            base_r = (r // 3)*3
            base_c = (c // 3)*3
            
            for i in range(base_r, base_r + 3):
                for j in range(base_c, base_c + 3):
                    if board[i][j] == num:
                        return False                    
            return True
        
        
        def getNext(r, c):
            if c==8 and r==8:
                return 9, 9
            if c == 8:
                return r+1, 0
            else:
                return r, c+1
            
            
        solve(0, 0)
