class Solution {
public:
    int rowArr[4] = {1, -1, 0, 0};
    int colArr[4] = {0, 0, 1, -1};
    
    bool isValid(vector<vector<char>>& grid, int i, int j){
        int R = grid.size();
        int C = grid[0].size();
        return i>=0 && i<R && j>=0 && j<C && grid[i][j] == '1';
    }
    
    void dfs(vector<vector<char>>& grid, int i, int j){
        
        grid[i][j] = '0';
        for(int k = 0; k<4; k++){
            int r = i + rowArr[k];
            int c = j + colArr[k];
            
            if(isValid(grid, r, c))
                dfs(grid, r, c);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        int rows = grid.size();
        int cols = grid[0].size();
        int cnt = 0;
      
        for(int i = 0; i<rows; i++){
            for(int j = 0; j<cols; j++){
                if(grid[i][j] == '1'){
                    dfs(grid, i, j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
