vector<vector<pair<int, int>>> start_pair{ {{0,0},{0,3},{0,6}},
	{{3,0},{3,3},{3,6}},
	{{6,0},{6,3},{6,6}}};
vector<vector<pair<int, int>>> end_pair{ {{2,2},{2,5},{2,8}},
	{{5,2},{5,5},{5,8} },
	{{ 8,2 }, { 8,5 }, {8,8 }} };



bool checkboard(vector<vector<char>>& board)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (board[i][j] == '.')
				return false;
		}
	}
	return true;
}


bool CheckHorizontal(vector<vector<char>>& board,int row, int col, char num)
{
	for (int i = 0; i < 9; i++)
	{
		if (i != col)
		{
			if (board[row][i] == num)
				return true;
		}
	}
	return false;
}

bool CheckVertical(vector<vector<char>>& board, int row, int col, char num)
{
	for (int i = 0; i < 9; i++)
	{
		if (i != row)
		{
			if (board[i][col] == num)
				return true;
		}
	}
	return false;
}
bool CheckBox(vector<vector<char>>& board, int row, int  col, char num)
{
	int box_row = row / 3;
	int box_col = col / 3;
	for (int i = start_pair[box_row][box_col].first; i <= end_pair[box_row][box_col].first; i++)
	{
		for (int j = start_pair[box_row][box_col].second; j <= end_pair[box_row][box_col].second; j++)
		{
			if (board[i][j] == num)
				return true;
		}
	}
	return false;
}

bool CheckNum(vector<vector<char>>& board,int row, int col, char num)
{
	return CheckHorizontal(board, row, col, num) || CheckVertical(board, row, col, num) || CheckBox(board, row, col, num);
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
			board[row][col] = num;
			if (solveSudokuUtil(board, idx + 1))
				return true;
			board[row][col] = '.';
		}
	}

	return false;
}



class Solution {
public:
void solveSudoku(vector<vector<char>>& board) {
	solveSudokuUtil(board, 0);
}
};