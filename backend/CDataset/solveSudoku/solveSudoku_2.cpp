class Solution {
public:
    bool ok(vector<vector<char>>& board, int a, int i, int j){
        // row
        for(int c=0;c<9;++c)
            if(board[i][c]-'0' == a)
                return 0;
        // col
        for(int r=0;r<9;++r)
            if(board[r][j]-'0' == a)
                return 0;
        // cell
        int br = i/3, bc = j/3;
        for(int r=br*3; r<br*3+3;++r)
            for(int c=bc*3; c<bc*3+3;++c)
                if(board[r][c]-'0' == a)
                    return 0;
        return 1;
    }
    
    bool dfs(vector<vector<char>>& board, int i, int j){
        if(i == 9) return 1;
        if(j == 9) return dfs(board,i+1,0);
        if(board[i][j] != '.') return dfs(board,i,j+1);
        for(int a=1;a<=9;++a){
            if(ok(board,a,i,j)){
                board[i][j] = a+'0';
                if(dfs(board,i,j+1)) 
                    return 1;
                board[i][j] = '.';
            }      
        }
        return 0;
    }
    void solveSudoku(vector<vector<char>>& board) {
        dfs(board,0,0);
    }
};
            
