class Solution {
public:
    int N = 9;
    bool isSafe(int i, int j, int num, vector<vector<char>>& board){
        //rows, colm
        char nn = num + '0';
        for(int x = 0; x < N; x++){
            if(board[x][j] == nn || board[i][x] == nn) return false; 
        }   
        //small box
        int ss = sqrt(N);
        int sr = i - i%ss;
        int sc = j - j%ss; 
        //small box-> i, j
        for (int y = 0; y < ss; y++){
            for(int z = 0; z < ss; z++){
                if(board[y + sr][z + sc] == nn) return false; 
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        //find first blank space
        int i, j, flag = 0;
        for(i = 0; i < N; i++){
            for(j = 0; j < N; j++){
                if(board[i][j] == '.'){
                    flag = 1;
                    break;}
            }
            if(flag) break;
        }   
        if(i == N || j == N) return true;    
        //black space -> [1-9]
        for(int num = 1; num <= 9; num++){
            if(isSafe(i, j, num, board)){
                board[i][j] = '0' + num;
                if(solve(board)) return true;
            }
            board[i][j] = '.';
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
