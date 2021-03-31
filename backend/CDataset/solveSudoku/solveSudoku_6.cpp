class Solution 
{
public:
	bool isValid(vector<vector<char>>& board, int row , int column, char c) 
	{
        //checking all columns in a given ROW
		for (int i = 0; i < 9; ++i)
			if (board[row][i] == c) return false;
        //checking all rows in a given COLUMN
		for (int j = 0; j < 9; ++j)
			if (board[j][column] == c) return false;
        //checking the 3*3 matrix starting from given ROW and COLUMN
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				if (board[row / 3 * 3 + i][column / 3 * 3 + j] == c)
					return false;
		return true;
	}
	bool solve(vector<vector<char>>& board) 
	{
        //traversing the given board
		for (int i = 0; i < 9; ++i)
		{
			for (int j = 0; j < 9; ++j)
			{
                //if location is unassigned
				if ('.' == board[i][j]) 
				{
                    //we can put 1 to 9 at unassigned locatiom
					for (int k = 0; k < 9; ++k)
					{
                        //checking we can put k or not [ means already present or not]
						if (isValid(board, i, j, '1' + k)) 
						{
                            //adding in a hope to get done
							board[i][j] = '1' + k;
                            //if solvable. yipieee return 1
							if (solve(board)) return true;
                            //else cry over your choice and trty other option
							else board[i][j] = '.';
						}
					}
                    //if we cant assign any number from 1 to 9 at that specified i and j
                    //location return 0;
					return false;
				}
			}
		}
		return 1;
	}
	void solveSudoku(vector<vector<char>>& board) 
	{
		solve(board);
	}
};
