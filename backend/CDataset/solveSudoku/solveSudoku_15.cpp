class Solution {
private:
	vector<vector<bool>>row;//row[i][j]表示第i行已经有了j+1这个数字
	vector<vector<bool>>col;//col[i][j]表示第i列已经有了j+1这个数字
	vector<vector<vector<bool>>>cube;//把9X9分成3x3x9个
	//cube[i][j][k]表示第i行第j列的3*3已经有了j+1这个数字
public:
	void solveSudoku(vector<vector<char>>& board) {
		row = vector<vector<bool>>(9, vector<bool>(9, false));
		col = vector<vector<bool>>(9, vector<bool>(9, false));
		cube = vector<vector<vector<bool>>>(3, vector<vector<bool>>(3, vector<bool>(9, false)));
		int n = 0;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (board[i][j] != '.') {
					row[i][board[i][j] - '1'] = true;
					col[j][board[i][j] - '1'] = true;
					cube[i / 3][j / 3][board[i][j] - '1'] = true;
					n++;
				}
			}
		}
		n = 81 - n;//需要填写数字的个数
		DFS(0, n, board);
		return;
	}
	bool DFS(int index, int n, vector<vector<char>>& board) {
		if (n == 0) {
			return true;
		}
		for (int i = index; i < 81; i++) {
			int x = i / 9;
			int y = i % 9;
			if (board[x][y] == '.') {
				for (int j = 1; j < 10; j++) {
					if (!row[x][j - 1] && !col[y][j - 1] &&
						!cube[x / 3][y / 3][j - 1]) {
						board[x][y] = j + 48;
						row[x][j - 1] = true;
						col[y][j - 1] = true;
						cube[x / 3][y / 3][j - 1] = true;
						n--;

						if (DFS(i + 1, n, board))
							return true;

						board[x][y] = '.';
						row[x][j - 1] = false;
						col[y][j - 1] = false;
						cube[x / 3][y / 3][j - 1] = false;
						n++;		
					}
				}
				return false;
			}
		}
		return false;
	}
};
