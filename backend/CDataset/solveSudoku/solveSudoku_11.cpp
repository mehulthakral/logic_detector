class Solution {
public:
    bool findunassignedindex(int &row,int &col,vector<vector<char>>& board)
    {
        for(row=0;row<9;row++)
        {
            for(col=0;col<9;col++)
            {
                if(board[row][col]=='.') return true;
            }
        }
        return false;
    }
    bool issafe(int row,int col,int num,vector<vector<char>>& board)
    {
        for(int i=0;i<9;i++) if(board[row][i]==num+48) return false;  // check safe row
        for(int i=0;i<9;i++) if(board[i][col]==num+48) return false;  // check safe col
        int boxrow = row - row%3;
        int boxcol = col - col%3;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(board[i+boxrow][j+boxcol]==num+48) return false;  // checks box
            }
        }
        return true;
    }
    bool valid(vector<vector<char>>& board)
    {
        int row,col;
        if(!findunassignedindex(row,col,board)) return true;
        
        for(int num=1;num<=9;num++)
        {
            if(issafe(row,col,num,board))
            {
                board[row][col] = num+48;
                if(valid(board)) return true;
                board[row][col] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        valid(board);
    }
};
