class Solution {
public:
    bool row[9][9] = {{false}};
    bool col[9][9] = {{false}};
    bool box[9][9] = {{false}};
    
    void solveSudoku(vector<vector<char>>& board) {
        int I,J;
        bool flag = false;
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                if (board[i][j] != '.'){
                    row[i][board[i][j]-48-1] = true;
                    col[j][board[i][j]-48-1] = true;
                    box[i/3*3+j/3][board[i][j]-48-1] = true;
                }
                else if (board[i][j] == '.' && !flag){
                    I = i, J = j;       // store the first empty position
                    flag = true;
                }
            }
        }
        backtrack(board, I, J);
    }
    
    bool backtrack(vector<vector<char>>& board, int i, int j){
        if (board[i][j] != '.'){
            bool valid = true;
            if (i == 8 && j == 8)
                return true;
            else if (i < 8 && j == 8)
                valid = backtrack(board, i+1, 0);
            else if (j < 8)
                valid = backtrack(board, i, j+1);
            return valid;
        }
            
        for (int val = 1; val <= 9; val++){
            if (row[i][val-1] == true || col[j][val-1] == true || box[i/3*3+j/3][val-1] == true)
                continue;
            board[i][j] = val+48;
            row[i][val-1] = true;
            col[j][val-1] = true;
            box[i/3*3+j/3][val-1] = true;
            
            bool valid = true;
            if (i == 8 && j == 8)
                return true;        // very last position
            else if (i < 8 && j == 8)
                valid = backtrack(board, i+1, 0);        // new row
            else if (j < 8)
                valid = backtrack(board, i, j+1);        // add one to column
            
            if(!valid){        // it's invalid with this "val" in [i][j], backtrack
                board[i][j] = '.';
                row[i][val-1] = false;
                col[j][val-1] = false;
                box[i/3*3+j/3][val-1] = false;
            }
            else
                return valid;        // return true
        }
        return false;        // current position is a dead end, go to previous position
    }
};
