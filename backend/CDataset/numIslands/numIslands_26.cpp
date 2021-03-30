class Solution {
public:
    void dfs(vector<vector<char>>& grid, int rows, int cols, int i, int j) {
        // cout << i << j << endl;
        grid[i][j] = '0';
        if ((i-1) >= 0 && grid[i-1][j] == '1') dfs(grid, rows, cols, i-1, j);
        if ((i+1) < rows && grid[i+1][j] == '1') dfs(grid, rows, cols, i+1, j);
        if ((j-1) >= 0 && grid[i][j-1] == '1') dfs(grid, rows, cols, i, j-1);
        if ((j+1) < cols && grid[i][j+1] == '1') dfs(grid, rows, cols, i, j+1);
        // return;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        if (!grid.size()) return 0;
        int rows = grid.size();
        int cols = grid[0].size();
        int numberIslands = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j]=='1') {
                    ++numberIslands;
                    dfs(grid, rows, cols, i, j);
                }
            }
        }
        return numberIslands;
    }
};
