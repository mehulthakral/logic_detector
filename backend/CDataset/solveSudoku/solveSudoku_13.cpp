#include <bitset>

static auto x = []() {ios_base::sync_with_stdio(false); cin.tie(NULL); return NULL; }();

class Solution
{
public:
    bitset<9> rowcheck[9], colcheck[9], matcheck[3][3];

    bool isValid(vector<vector<char>> &board, int row, int col, char val)
    {
        if (rowcheck[row].test(val)){ return false; }
        if (colcheck[col].test(val)){ return false; }
        if (matcheck[row / 3][col / 3].test(val)){ return false; }
        return true;
    }

    bool solveSudoku(vector<vector<char>> &board, int row, int col)
    {
        while (row < 9 && board[row][col] != '.')
        {
            col++;
            if (col == 9){ col = 0, ++row; }
        }
        if (row == 9){ return true; }

        for (int v = 0; v < 9; v++)
        {
            if (isValid(board, row, col, v))
            {
                board[row][col] = v + 1 + '0';
                rowcheck[row].set(v);
                colcheck[col].set(v);
                matcheck[row / 3][col / 3].set(v);
                if (solveSudoku(board, row, col)){ return true; }

                board[row][col] = '.';
                rowcheck[row].reset(v);
                colcheck[col].reset(v);
                matcheck[row / 3][col / 3].reset(v);
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>> &board)
    {

        for (int row = 0; row < 9; row++)
            for (int col = 0; col < 9; col++)
                if (board[row][col] != '.')
                {
                    int v = board[row][col] - '0' - 1;
                    rowcheck[row].set(v);
                    colcheck[col].set(v);
                    matcheck[row / 3][col / 3].set(v);
                }

        solveSudoku(board, 0, 0);
    }
};
