class Solution {
    private:
    vector<int> nextDot(vector<vector<char>>& board){
        vector<int> a(2,-1);
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++)
                if(board[i][j]=='.')
                {
                    a[0]=i;
                    a[1]=j;
                }
        }
return a;
        
    }
    
    bool isValid(vector<vector<char>>& board,int num,int row,int col){
        for(int i=0;i<board[0].size();i++)
            if(board[row][i]==num)
                return false;
        for(int j=0;j<board.size();j++)
            if(board[j][col]==num)
                return false;
        int boxRow=3*(row/3);
        int boxCol=3*(col/3);
        for(int i=boxRow;i<boxRow+3;i++)
            for(int j=boxCol;j<boxCol+3;j++)
                if(board[i][j]==num)
                    return false;
        return true;
    }
public:
    bool solveSudoku(vector<vector<char>>& board) {
             vector<int> newDot=nextDot(board);
        if(newDot[0]==-1 && newDot[1]==-1)
            return true;
   
        int row=newDot[0];
        int col=newDot[1];
        char c;
      for(int num=1;num<10;num++)
            {
                 if(num==1)
                   c='1';
                 else if(num==2)
                   c='2';
                 else if(num==3)
                   c='3';
                 else if(num==4)
                   c='4';
                 else if(num==5)
                   c='5';
                 else if(num==6)
                    c='6';
                 else if(num==7)
                    c='7';
                 else if(num==8)
                    c='8';
                 else
                    c='9';
                
                if(isValid(board,c,row,col)){
                              
                 board[row][col]=c;
                   
                    if(solveSudoku(board))
                        return true;
                    //backtracking
                        board[row][col]='.';
                }
        
            }
        return false;
    }
};
