bool row[9][9]={}, col[9][9]={}, block[9][9]={};
void solveSudoku(vector<vector<char>>& board) {
    int num, k;
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            if(board[i][j]!='.') {
                num = board[i][j]-'1'; 
                k = i/3*3 + j/3;
                row[i][num] = col[j][num] = block[k][num] = 1;
            }
        }
    }
    Helper(board, 0);
}
bool Helper(vector<vector<char>>& b, int ind){
    if(ind==81) return true; 
    int i=ind/9, j=ind%9, num, k;
    if(b[i][j]!='.') return Helper(b, ind+1);
    else{
        for(char f='1'; f<='9'; f++){
            num = f-'1'; 
            k= i/3*3 + j/3;
            if(!row[i][num] && !col[j][num] && !block[k][num]){
                b[i][j]= f;
                row[i][num] = col[j][num] = block[k][num] = 1;
                if(Helper(b, ind+1)) return true;                
                b[i][j]='.';
                row[i][num] = col[j][num] = block[k][num] = 0;
            }
        }
        return false;
    }
}
