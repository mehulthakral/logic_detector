class Solution {
public:
    bool backtrack(vector<vector<char>>& board, vector<vector<bool>>& used1, vector<vector<bool>>& used2, vector<vector<bool>>& used3){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.') continue;
                for(int k = 0; k < 9; k++){
                    int box = i / 3 * 3 + j / 3;
                    if(!used1[i][k] && !used2[j][k] && !used3[box][k]){
                        board[i][j] = k + '1';
                        used1[i][k] = used2[j][k] = used3[box][k] = true;
                        if(backtrack(board, used1, used2, used3)) return true;
                    }
                    board[i][j] = '.';
                    used1[i][k] = used2[j][k] = used3[box][k] = false;
                }
                return false;
            }
        }
        return true;
    }
        
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> used1(9, vector<bool>(9, false)); // for rows
        vector<vector<bool>> used2(9, vector<bool>(9, false)); // for columns
        vector<vector<bool>> used3(9, vector<bool>(9, false)); // for 3x3 sub-boxes
        // initialize used arrays according to initial board
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    int k = board[i][j] - '1', box = i / 3 * 3 + j / 3;
                    used1[i][k] = used2[j][k] = used3[box][k] = true;
                }
            }
        }   
        // solve Sudoku
        backtrack(board, used1, used2, used3);
    }
};