class Solution:
    def solveSudoku(self, board:List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        def validNumber(row: int, col:int, n:str)->bool:
            cols = set(list(zip(*board))[col][:])
            rows = set(board[row][:])
            if n in cols: return False
            if n in rows: return False
            row0 = row//3
            col0 = col//3
            for i in range(row0*3, row0*3 + 3):
                for j in range(col0*3, col0*3 + 3):
                    if n == board[i][j]: return False
            return True
        
        def getAllElement()->set:
            ele = set()
            for e in board:
                for k in e:
                    ele.add(k)
            return ele
        
        def helper()->None:
            for row in range(0,9):
                for col in range(0,9):
                    if board[row][col] == '.':
                        for n in range(1,10):
                            if validNumber(row, col, str(n)):
                                board[row][col] = str(n)
                                helper()
                                if "." in getAllElement():
                                    board[row][col]="."
                        return 
        helper()
        return 
