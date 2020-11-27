class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        
        def can_place(i, j, num):
            # Check row
            if any(num == n for n in board[i]):
                return False
            
            # Check col
            if any(num == n for n in list(zip(*board))[j]):
                return False
            
            # Check box
            start_row, start_col = (i // 3) * 3, (j // 3) * 3
            for r in range(start_row, start_row + 3):
                for c in range(start_col, start_col + 3):
                    if num == board[r][c]:
                        return False
            return True
        
        def find_unassigned():
            for r in range(len(board)):
                for c in range(len(board[0])):
                    if board[r][c] == '.':
                        return r, c
            return -1, -1
        
        def solve():
            r, c = find_unassigned()
            
            if r == -1 and c == -1:
                return True
            
            for num in [str(n) for n in range(1, 10)]:
                if can_place(r, c, num):
                    board[r][c] = num
                    if solve():
                        return True
                    board[r][c] = '.'
            return False
		
        if not board:
            return
        solve()
