class Solution:

    """
    * i, j -> index
    * bit -> 2^n, n -> number to be check
    * here we will set and unset the nTH bit
    """
    def toggle(self, i, j, bit):
        self.row[i] = self.row[i]^bit
        self.col[j] = self.col[j]^bit
        self.block[(i//3)*3 + j//3] = self.block[(i//3)*3 + j//3]^bit
        
    """
    * i, j -> index
    * bit -> 2^n, n -> number to be check
    * I will check weather the (n)th bit the row[i] is ON or OFF
    * if it is ON
    *       that means n is already present is that row and we cannont place another n
    * if it is OFF
    *       that means we are good to go 
    * same goes for col and block
    """
     
    def issafe(self, i , j, bit):
        if (bit & self.row[i]) != 0:
            return False
        if (bit & self.col[j]) != 0:
            return False
        if (bit & self.block[(i//3)*3 + j//3]) != 0:
            return False
        return True
    
    """
    * board -> baord
    * boxno -> (0 - 80) instead of passing i and j , i'm gonna pass boxno and later convert it into i and j
    """
        
    def solve(self, board, boxno):
        i  = boxno // 9 
        j  = boxno % 9
        
        if boxno == 81:
            return True

        if board[i][j] != '.':
            return self.solve(board, boxno+1)
        
        else:
            for k in range(1, 10):
                bit  = 1 << k
                if self.issafe(i,j,bit):
                    
                    self.toggle(i, j, bit)
                    board[i][j]= str(k)
                    
                    if self.solve(board, boxno + 1) : 
                        return True
                    
                    board[i][j]= '.'
                    self.toggle(i, j, bit)
                    
        return False            
    
    def init(self):
        self.row = []       # to check weather, we have nunber x 
                            # in the specific row, col, and block(grid) 
        self.col = []
        self.block = []
        for i in range(1, 10):
            self.row.append(0)
            self.col.append(0)
            self.block.append(0)
            
            
    def solveSudoku(self, board:List[List[str]])->None:
        self.init()
        for i in range(0, 9):
            for j in range(0, 9):
                if board[i][j] != '.':
                    self.toggle(i, j,(1 << int(board[i][j])) )
                    
                    
        self.solve(board, 0)

                
        """
        Do not return anything, modify board in-place instead.
        """
        
