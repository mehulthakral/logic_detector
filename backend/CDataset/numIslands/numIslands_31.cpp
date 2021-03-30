class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0) return 0;
        int row = grid.size();
        int col = grid[0].size();
        int flag = 0;
        vector<vector<int>> M(row, vector<int>(col, 0));
        vector<vector<int>> visited(row, vector<int>(col, 0));
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(grid[i][j] == '1' && M[i][j] == 0) {
                    dfs(grid, M, visited, i, j, ++flag);
                } else {
                    continue;
                }
            }
        }
        return flag;
    }
    
    void dfs(vector<vector<char>>& grid, vector<vector<int>>& M, vector<vector<int>>& visited, int i, int j, int flag) {
        if(i < 0 || j < 0 || i == grid.size() || j == grid[0].size() || visited[i][j] == 1) {
            return;
        } else if(grid[i][j] == '0') {
            visited[i][j] = 1;
            return;
        }
        
        if(grid[i][j] == '1') {
            M[i][j] = flag;
            visited[i][j] = 1;
            dfs(grid, M, visited, i, j - 1, flag);
            dfs(grid, M, visited, i - 1, j, flag);
            dfs(grid, M, visited, i, j + 1, flag);
            dfs(grid, M, visited, i + 1, j, flag);
        }
        
        return;
    }
};
