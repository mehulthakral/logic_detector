class Solution {
public:
void solveSudoku(vector<vector<char>>& board) {
    helper(board, 0);
}
bool helper(vector<vector<char>>& b, int ind){
    if(ind==81) return true; 
    int i=ind/9, j=ind%9;
    if(b[i][j]!='.') return helper(b, ind+1);
    else{
        for(char f = '1'; f <= '9'; f++){
            if(isValidFill(b, i, j, f)){
                b[i][j]= f;
                if(helper(b, ind+1)) return true;                
                b[i][j]='.';
            }
        }
        return false;
    }
}
bool isValidFill(vector<vector<char>>& b, int i, int j, char fill) {
    for(int k=0; k<9; k++){
        int r= i/3*3+j/3;   //select the block
        if(b[i][k]==fill || b[k][j]==fill || b[r/3*3+k/3][r%3*3+k%3]==fill) 
            return false; //check row, column, block
    }            
    return true;
}
};