from typing import List
class Solution:
	def __init__(self):
		self.size = 9
		
		self.sudoku_values = {'1', '2', '3', '4', '5', '6', '7', '8', '9'}
		self.empty = '.'
		
		self.row_no = lambda cell_no: cell_no // self.size # Get row from cell. no
		self.col_no = lambda cell_no: cell_no % self.size  # Get col from cell. no
		self.box_no = lambda r, c: 3 * (r // 3) + c // 3   # Get box from row and column
		
		self.rows_values = {}  # {row: sudoku values set}
		self.cols_values = {}  # {col: sudoku values set}
		self.boxs_values = {}  # {box: sudoku values set}

	def solveSudoku(self, board: List[List[str]]) -> None:
		
		# 1. Initialization: Store all board values
		for i in range(self.size):
			self.rows_values[i] = set()
			self.cols_values[i] = set()
			self.boxs_values[i] = set()

		for r in range(self.size):
			for c in range(self.size):
				if board[r][c] != self.empty:
					self.rows_values[r].add(board[r][c])
					self.cols_values[c].add(board[r][c])
					self.boxs_values[self.box_no(r, c)].add(board[r][c])
		
		# 2. Backtrack from cell no: 0
		self.backtrack(0, board)

		return board

	def backtrack(self, cell_no, board):
		# Base case: we filled all empty cells
		if cell_no == 81: 
			return True

		r, c = self.row_no(cell_no), self.col_no(cell_no)

		if board[r][c] != self.empty:
			return self.backtrack(cell_no + 1, board)

		for val in self.sudoku_values:
			# could_place? Is valid?
			if val in self.rows_values[r] or val in self.cols_values[c] or val in self.boxs_values[self.box_no(r, c)]:
				continue

			# place:
			board[r][c] = val
			self.rows_values[r].add(val)
			self.cols_values[c].add(val)
			self.boxs_values[self.box_no(r, c)].add(val)
			
			# next:
			if self.backtrack(cell_no + 1, board):
				return True

			# remove:
			board[r][c] = self.empty
			self.rows_values[r].remove(val)
			self.cols_values[c].remove(val)
			self.boxs_values[self.box_no(r, c)].remove(val)

		return False
		
