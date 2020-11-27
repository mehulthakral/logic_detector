class Solution:
    def getPosNums(self, board, position, rows, columns, sub_boxes):
        nums = []
        row, column = position
        box_idx = (row//3)*3 + column//3
        for s in map(str,range(1,10)):
            if (not s in rows[row]) and (not s in columns[column]) and (not s in sub_boxes[box_idx]):
                nums.append(s)
        return nums
    
    
    
    def init(self, board, emptyPos, rows, columns, sub_boxes):
        ## fill rows, columns, sub_boxes and emptyPos keys
        for i in range(9):
            for j in range(9):
                tmp = board[i][j]
                if tmp != '.':
                    rows[i].add(tmp)
                    columns[j].add(tmp)
                    box_idx = (i//3)*3+(j//3)
                    sub_boxes[box_idx].add(tmp)
                else:
                    emptyPos.append((i,j))
        return
        
        
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        
        emptyPos = []       # record empty position(row,column)
        rows = [set() for i in range(9)]    # record numbers in each rows
        columns = [set() for i in range(9)] # record numbers in each columns
        sub_boxes = [set() for i in range(9)]   #record numbers in each sub-boxes
        
        self.init(board, emptyPos, rows, columns, sub_boxes)
        

        def solve(board, positions):
            if not positions:       # if all empty positions are filled, it's done
                return True
            
            # we are working on first empty position
            # find all possible numbers on this position
            posNums = self.getPosNums(board, positions[0], rows, columns, sub_boxes)
            
            if not posNums:     #if there is no available numbers on this position, it's fail
                return False
            
            row, column = positions[0]
            box_idx = (row//3)*3 + (column//3)
            for s in posNums:
                board[row][column] = s
                rows[row].add(s)
                columns[column].add(s)
                sub_boxes[box_idx].add(s)
                
                if solve(board, positions[1:]):
                    return True
                
                rows[row].remove(s)
                columns[column].remove(s)
                sub_boxes[box_idx].remove(s)
                
            
            # if all possible numbers don't work, it's fail.            
            board[row][column] = '.'                    
            return False        
        
        solve(board, emptyPos)
        return
