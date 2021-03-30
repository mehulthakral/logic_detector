class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
         helper(board,0,0);
    }
    int helper(vector<vector<char>>& board, int row, int col)
    {
        if(row==9)
            return 1;
        if(board[row][col]!='.')
        {
            if(col+1==9)
            {
                return helper(board,row+1,0);
            }
            else
            {
                return helper(board,row,col+1);
            }
        }
        else
        {
           for(int i=1;i<=9;i++)
           {
               char b=i+'0';
               if(isvalid(board,row,col,b))
               {
                   board[row][col]=b;
                   int a=0;
                   if(col+1==9)
                       a=helper(board,row+1,0);
                   else
                       a=helper(board,row,col+1);
                   if(a==1)
                       return 1;
                   board[row][col]='.';
               }
           }
        }
        return -1;
    }
    
    bool isvalid(vector<vector<char>>& board, int row, int col,char b)
    {
        for(int i=0;i<9;i++)
        {
            if(board[row][i]==b || board[i][col]==b)
                return false;
        }
        return isvalidgrid(board,row,col,b);
    }
    bool isvalidgrid(vector<vector<char>>& board, int row, int col, char b)
    {
        int startR=(row/3)*3;
        int startC=(col/3)*3;
        
        for(int i=startR;i<startR+3;i++)
        {
            for(int j=startC;j<startC+3;j++)
            {
                if(board[i][j]==b)
                    return false;
            }
        }
        return true;
    }
    
};
