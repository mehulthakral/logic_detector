class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& grid, int rows, int cols){
        if(i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] == '0') return;
        grid[i][j] = '0';
        dfs(i - 1, j, grid, rows, cols);
        dfs(i + 1, j, grid, rows, cols);
        dfs(i, j - 1, grid, rows, cols);
        dfs(i, j + 1, grid, rows, cols);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0) return 0;
        int rows = grid.size();
        int cols = grid[0].size();
        int cnt = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == '1'){
                    dfs(i, j, grid, rows, cols);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};