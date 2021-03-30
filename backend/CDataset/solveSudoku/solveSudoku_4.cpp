class Solution {
public:
    bool isSafe(vector<vector<char>>& board,int row,int col,int n){
        int cnt=0;
        for(int i=0;i<n;i++){
            cnt+=board[i][col]==board[row][col];
        }
        for(int i=0;i<n;i++){
            cnt+=board[row][i]==board[row][col];
        }
        int block_row=(row/3)*3;
        int block_col=(col/3)*3;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                cnt+=board[block_row+i][block_col+j]==board[row][col];
            }
        }
        return cnt==3;
    }
    bool sudoku(vector<vector<char>>& board,int row,int col,int n){
        if(col==n){
            col=0;row++;
        }
        if(row==n) return true;
        if(board[row][col]=='.'){
            for(int i=1;i<=9;i++){
                board[row][col]=i+'0';
                if(isSafe(board,row,col,n)&&sudoku(board,row,col+1,n))
                    return true;
                board[row][col]='.';
            }
        }
        else{
            return sudoku(board,row,col+1,n);
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        int n=board.size();
        cout<<sudoku(board,0,0,n);
    }
};
