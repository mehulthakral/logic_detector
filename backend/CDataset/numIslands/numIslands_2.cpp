class Solution {
public:
    void dfs(vector<vector<char>> &grid, int row, int col){
        int ROWS = grid.size();
        int COLS = grid[0].size();
        
        if(row>=ROWS || row<0 || col>=COLS || col<0 || grid[row][col]=='2' || grid[row][col]=='0')
            return;
        
        grid[row][col] = '2';
        
        dfs(grid,row-1,col);
        dfs(grid, row, col-1);
        dfs(grid, row, col+1);
        dfs(grid, row+1, col);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        int ROWS = grid.size();
        int COLS = grid[0].size();
        
        int count = 0;
        
        for(int i=0;i<ROWS;i++){
            for(int j=0;j<COLS;j++){
                if(grid[i][j]=='1'){
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        
        return count++;
    }
};
