from typing import List
class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        ## RC ##
		## APPROACH : BACKTRACKING ##
		## Similar to Leetcode : 51. N Queens, 36. Valid Sudoku ##
		## Time Complexity: O(9^(m * n))
        ## Space Complexity: O(m*n)
	
        n = len(board)        
        rows= [set() for _ in range(n)]
        cols = [set() for _ in range(n)]
        grids = [set() for _ in range(n)]
        
        def add_val_to_board(row, col, val):
            rows[row].add( val )
            cols[col].add( val )
            grids[(row//3)*3+ (col//3)].add( val )
            board[row][col] = str(val)
            
        def remove_val_from_board(row, col, val):
            rows[row].remove( val )
            cols[col].remove( val )
            grids[(row//3)*3+ (col//3)].remove( val )
            board[row][col] = "."
        
        def fill_board(row, col, val, board):
            
            if( row < 0 or col < 0 or row >= n or col >= n ):
                return
            
            ## GIST, incrementing row and col here
            while not board[row][col] == '.':
                col += 1
                if col == 9: 
                    col, row = 0, row+1
                if row == 9: 
                    return True
                
            for val in range( 1, n+1 ):
                if( val in rows[row] or val in cols[col] or val in grids[(row//3)*3+ (col//3)]):
                    continue
                    
                add_val_to_board(row, col, val)

                if( fill_board(row, col, val, board) ):
                    return board
                
                remove_val_from_board(row, col, val)

        for i in range(n):
            for j in range(n):
                if( not board[i][j] == "." ):
                    add_val_to_board( i, j, int(board[i][j]) )
        
        return fill_board(0, 0, board[0][0], board)
