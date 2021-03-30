class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int row, int col, int count)
    {
        char c=count+48;
        //cout<<c<<endl;
        for(int i=0; i<9; i++)
        {
            if(board[i][col]==c) return false;
        }
        for(int j=0; j<9; j++)
        {
            if(board[row][j]==c) return false;
        }
        int br=row/3, bc=col/3;
        br = br*3;
        bc = bc*3;
        int rl=br+3, cl=bc+3;
        for(int i=br; i<rl; i++)
        {
            for(int j=bc; j<cl; j++)
            {
                if(board[i][j]==c) return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board)
    {
        int row, col;
        int k=0, i, j;
        for(i=0; i<9 && k==0; i++)
        {
            for(j=0; j<9; j++)
            {
                if(board[i][j]!='.') continue;
                row=i, col=j;
                k = 1;
                break;
            }
        }
        if(i==9 && j==9) return true;
        for(int count=1; count<=9; count++)
        {
            if(isSafe(board, row, col, count))
            {
                //cout<<row<<" "<<col<<endl;
                board[row][col] = count+48;
                if(solve(board)) return true;
                board[row][col] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) 
    {
        solve(board);
    }
};
