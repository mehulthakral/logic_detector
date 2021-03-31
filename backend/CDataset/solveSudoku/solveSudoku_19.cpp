class Solution 
{
public:
	// determine the board is valid or not.
	bool isValid(vector<vector<char>>& board, int row , int column, char c) 
	{
		for (int i = 0; i < 9; ++i)
			if (board[row][i] == c) return false;
		for (int j = 0; j < 9; ++j)
			if (board[j][column] == c) return false;
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				if (board[row / 3 * 3 + i][column / 3 * 3 + j] == c)
					return false;
		return true;
	}
	bool solve(vector<vector<char>>& board) 
	{
		for (int i = 0; i < 9; ++i)
		{
			for (int j = 0; j < 9; ++j)
			{
				if ('.' == board[i][j]) 
				{
					for (int k = 0; k < 9; ++k)
					{
						if (isValid(board, i, j, '1' + k)) 
						{
							board[i][j] = '1' + k;
							if (solve(board)) return true;
							else board[i][j] = '.';
						}
					}
					return false;
				}
			}
		}
		return true;
	}
	void solveSudoku(vector<vector<char>>& board) 
	{
		solve(board);
	}
};