class Solution {
public:
bool row_wise[9][9] = { {false} };
bool col_wise[9][9] = { {false} };
bool box_wise[9][9] = { {false} };

bool CheckHorizontal(vector<vector<char>>& board,int row, int col, char num)
{
	return row_wise[row][num - '0' - 1];
}

bool CheckVertical(vector<vector<char>>& board, int row, int col, char num)
{
	return col_wise[col][num - '0' - 1];
}
bool CheckBox(vector<vector<char>>& board, int row, int  col, char num)
{
	return box_wise[(row / 3) * 3 + (col / 3)][num - '0' - 1];
}

bool CheckNum(vector<vector<char>>& board,int row, int col, char num)
{
	return CheckHorizontal(board, row, col, num) || CheckVertical(board, row, col, num) || CheckBox(board, row, col, num);
}

void SetBoard(vector<vector<char>>& board, char num,bool b_val,int row,int col)
{
	if (b_val)
		board[row][col] = num;
	else
		board[row][col] = '.';
	row_wise[row][num - '0' - 1] = b_val;
	col_wise[col][num - '0' - 1] = b_val;
	box_wise[(row / 3) * 3 + (col / 3)][num - '0' - 1] = b_val;
}
bool solveSudokuUtil(vector<vector<char>>& board, int idx)
{
	if (idx >= 81)
		return true;

	int row = idx / 9;
	int col = idx % 9;
	if (board[row][col] != '.')
		return solveSudokuUtil(board, idx + 1);

	char num;
	for (num = '1'; num <= '9'; num++)
	{
		if (!CheckNum(board,row,col,num))
		{
			SetBoard(board, num, true, row, col);
			if (solveSudokuUtil(board, idx + 1))
				return true;
			SetBoard(board, num, false, row, col);
		}
	}

	return false;
}

void solveSudoku(vector<vector<char>>& board) {
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (board[i][j] != '.')
			{
				row_wise[i][board[i][j] - '0' - 1] = true;
				col_wise[j][board[i][j] - '0' - 1] = true;
				box_wise[(i / 3) * 3 + (j / 3)][board[i][j] - '0' - 1] = true;
			}
		}
	}
	solveSudokuUtil(board, 0);
}
};