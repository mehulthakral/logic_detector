from typing import List, Tuple


class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        row, col, cube, empties = self._boardStats(board)
        self._solveSudoku(board, row, col, cube, empties)

    def _boardStats(self, board: List[List[str]]) -> Tuple[List[int], List[int], List[List[int]],List[Tuple[int, int]]]:
        """
        :param board:
        :return: masks of included digits in rows, columns, 3x3
        and cords of empties values
        """
        # Define masks that indicate included digits in a row, col and 3x3 quadratic
        row, col = [0] * 9, [0] * 9
        cube = [[0] * 3 for _ in range(3)]
        empties = []  # Cords of empties values('.')
        for i in range(9):
            for j in range(9):
                if board[i][j] == ".":
                    empties.append((i, j))
                else:
                    hashed = 1 << (int(board[i][j]) - 1)  # Generate mask for digit
                    # Added digit mask by bitwise operation(OR)
                    row[i] |= hashed
                    col[j] |= hashed
                    cube[i // 3][j // 3] |= hashed
        return row, col, cube, empties

    @staticmethod
    def _freeDigitMask(row: int, col: int, cube: int) -> int:
        """
        This method returns masks of free digits.
        :param row: mask of occupied digits of the row
        :param col: mask of occupied digits of the columns
        :param cube: mask of occupied digits of the 3x3 quadratic
        :return: mask of free digits
        """
        v = (1 << 9) - 1  # Mask of all possible digits(1-9), i.e, 0b111111111
        mask = (v - row) & (v - col) & (v - cube)  # Intersection of free digits
        return mask

    def _solveSudoku(
        self,
        board: List[List[str]],
        row: List[int],
        col: List[int],
        cube: List[List[int]],
        empties: List[Tuple[int, int]],
        k: int = 0,
    ) -> bool:
        if k >= len(empties):
            return True  # Found a solution if out of the bounding
        i, j = empties[k]  # Cords of empty cell
        mask = self._freeDigitMask(row[i], col[j], cube[i // 3][j // 3])
        if mask == 0:  # If mask equals to 0 then not have a solution
            return False
        for shift in range(9):
            h = 1 << shift
            if mask & h:  # Check is digit free
                # Add digit to the masks
                row[i] |= h
                col[j] |= h
                cube[i // 3][j // 3] |= h
                solved = self._solveSudoku(board, row, col, cube, empties, k + 1)
                if solved:
                    board[i][j] = str(shift + 1)
                    return True
                else:
                    # Remove digit to the masks
                    row[i] -= h
                    col[j] -= h
                    cube[i // 3][j // 3] -= h
        return False

