class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        def unique_vals(row, col):
            transpose = list(map(list, zip(*board)))
            colstart, rowstart = (col // 3) * 3, (row // 3) * 3 # topleft corner of each 3 by 3 square
            three_by_three = [board[i][j] 
							  for i in range(rowstart, rowstart + 3) 
							  for j in range(colstart, colstart + 3)]
            return set(string.digits[1:]) - set(board[row] + transpose[col] + three_by_three) - set('.')
            
        def solve(i):
            if i == 81:
                return True
            row, col = i // 9, i % 9
            if board[row][col] == '.':
                for val in unique_vals(row, col):
                    board[row][col] = val
                    if solve(i + 1):
                        return True
                    board[row][col] = '.'
            else:
                 if solve(i + 1):
                    return True
            return False

        solve(0)
