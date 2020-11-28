class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
		# Function to get all the possible values for a blank space
        def getPoss(board, a, b):
            candidates = []
            
            for i in range(1, 10):
                collision = False
                for j in range(9):
                  if board[a][j] == str(i) or\
                     board[j][b] == str(i) or\
                     board[(a - a%3) + j//3][(b - b%3) + j%3] == str(i):
                    collision = True
                    break
                if not collision:
                  candidates.append(str(i))

            return candidates
        
        def sudoku_solver(board):
            poten_vals = None
            bs_avlb = False
            a, b = -1, -1
            flag = False
            for i in range(len(board)):
                for j in range(len(board[0])):
                  if board[i][j] == '.':
                    bs_avlb = True
                    poten_vals = getPoss(board, i, j)
                    a, b = i, j
                    flag = True
                    break
                if flag:
                  break

            if not bs_avlb:    # if already all the blank spaces are filled
                return True
            
            for val in poten_vals:
                board[a][b] = val
                if sudoku_solver(board):      # ie. using this val is correct and doesn't cause any conflict later
                  return True
                board[a][b] = '.'
            return False       # backtrack
        
        sudoku_solver(board)
