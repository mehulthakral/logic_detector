class Solution:
    # 384ms
    def solveSudoku(self, board: List[List[str]]) -> None:

        # convert str to int, "." to 0, 
		# doing this means i cannot do it in-place, i will make board = str(board1) at the end
        board1 = [[int(val) if val.isdigit() else 0 for val in row ] for row in board]

        def is_valid(i, j, val):
            # check row
            if val in board1[i]: return False
            # check col
            if val in [board1[r][j] for r in range(9)]: return False
            # check block (grp)
            grp_r, grp_c = i//3, j//3
            for r in range(3):
                for c in range(3):
                    if board1[grp_r*3 + r][grp_c*3 + c] == val: return False
            return True

        def backtrack(pos=0):
            if pos == len(need): return True # reach the end, no more val left
            i, j = need[pos] # get the coordinates from need
            for num in range(1,10):
                if is_valid(i, j, num):
                    board1[i][j] = num
                    if backtrack(pos+1): return True
            # still not valid, reset val and backtrack
            board1[i][j] = 0
			
        # list out those cells == 0
        need = [(i, j) for i in range(9) for j in range(9) if not board1[i][j]]
		
        backtrack()
		
        # convert int to str
        board[:]=[[str(val) for val in row] for row in board1]
