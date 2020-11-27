class Solution:
    def __init__(self):
        self.answer_found = False

    def solveSudoku(self, board:List[List[str]])->None:
        """
        Do not return anything, modify board in-place instead.
        """
        # 1) DECLARE CONSTANTS
        n = len(board)
        NULL_CHAR = "."

        # 2) FUNCTION DEFINITIONS
        def place(board, number_str, row, col):
            board[row][col] = number_str

        def is_empty(board, row, col):
            return(board[row][col] == NULL_CHAR)
        
        def is_valid_placement(board, number_str, row, col):
            # check along column by fixing col, alow r to vary
            for r in range(n):
                if board[r][col] == number_str:
                    return(False)
            # check along row by fixing row, along c to vary
            for c in range(n):
                if board[row][c] == number_str:
                    return(False)
            # check 3X3 grid within which board[row][col] lies
            row_start = 3*(row // 3)
            col_start = 3*(col // 3)
            rows_to_check = [r for r in range(row_start, row_start + 3)]
            cols_to_check = [c for c in range(col_start, col_start + 3)]
            for r in rows_to_check:
                for c in cols_to_check:
                    if board[r][c] == number_str:
                        return(False)
            # if none of the above conditions are violated, placement is valid
            return(True)

        def backtrack(board, row, col):
            '''
              backtrack (i.e. reset value) only if answer_found is False
              since we need to modify board in-place - we don't want to
              overwrite a solved board
            '''
            if not self.answer_found:
                board[row][col] = NULL_CHAR

        def recursively_fill_board(board, row, col):
            '''
             place a value in a cell, and call recursive_fill on next
             cell if placement is valid, backtrack (reset value in cell)
             at the end of a for-loop iteration.
            '''
            if is_empty(board, row, col):
                
                for number in range(1, n+1):
                    number_str = str(number)
                    if (not self.answer_found 
                        and is_valid_placement(board, number_str, row, col)):
                        place(board, number_str, row, col)
                        if col < n - 1:
                            recursively_fill_board(board, row, col+1)
                        elif row < n - 1:
                            recursively_fill_board(board, row+1, col=0)
                        else:
                            # row = col = n - 1 i.e. last cell
                            if not self.answer_found:
                                self.answer_found = True
                
                        backtrack(board, row, col)

            elif col < n - 1:
                        recursively_fill_board(board, row, col+1)
            elif row < n - 1:
                recursively_fill_board(board, row+1, col=0)
            else:
                # row = col = n - 1 i.e. last cell
                if not self.answer_found:
                    self.answer_found = True

        # 3) CALL recursively_fill_board on cell 0,0 of board
        recursively_fill_board(board, row=0, col=0)
