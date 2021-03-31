class Solution {
public:
    bool isValid(vector<vector<char>>& board, int i, int j){
        char k = board[i][j];
        for(int c = 0; c < 9; c++)
            if(c != j && board[i][c] == k) return false;
        for(int r = 0; r < 9; r++)
            if(r != i && board[r][j] == k) return false;
        for(int r = i / 3 * 3; r < (i / 3 + 1) * 3; r++)
            for(int c = j / 3 * 3; c < (j / 3 + 1) * 3; c++)
                if(r != i && c != j && board[r][c] == k) return false;
        return true;
        
    }
    
    bool backtrack(vector<vector<char>>& board){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.') continue;
                for(char k = '1'; k <= '9'; k++){
                    board[i][j] = k;
                    if(isValid(board, i, j))
                        if(backtrack(board)) return true;
                    board[i][j] = '.';
                }
                return false;
            }
        }
        return true;
    }
        
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board);
    }
};