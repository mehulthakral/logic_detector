class Solution {
public:
    bool col[10][10],row[10][10],f[10][10];
    bool flag = false;
    void solveSudoku(vector<vector<char>>& board) {
         memset(col,false,sizeof(col));
         memset(row,false,sizeof(row));
         memset(f,false,sizeof(f));
         for(int i = 0; i < 9;i++){
             for(int j = 0; j < 9;j++){
                 if(board[i][j] == '.')   continue;
                 int temp = 3*(i/3)+j/3;
                 int num = board[i][j]-'0';
                 col[j][num] = row[i][num] = f[temp][num] = true;
             }
         }
         dfs(board,0,0);
    }
    void dfs(vector<vector<char>>& board,int i,int j){
        if(flag == true)  return ;
        if(i >= 9){
            flag = true;
            return ;
        }
        if(board[i][j] != '.'){
             if(j < 8)  dfs(board,i,j+1);
             else dfs(board,i+1,0);
             if(flag)  return;
        }
        
        else{
            int temp = 3*(i/3)+j/3;
            for(int n = 1; n <= 9; n++){
                if(!col[j][n] && !row[i][n] && !f[temp][n]){
                    board[i][j] = n + '0';
                    col[j][n] = row[i][n] = f[temp][n] = true;
                    if(j < 8)  dfs(board,i,j+1);
                    else dfs(board,i+1,0);
                    col[j][n] = row[i][n] = f[temp][n] = false;
                    if(flag)  return;
                }
            }
            board[i][j] = '.';
        }
    }
};