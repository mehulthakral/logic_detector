class Solution {
public:
    int x[4] = {-1, 0, 1, 0};
    int y[4] = {0, 1, 0, -1};

    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        if (i < 0 || j < 0 || i > grid.size()-1 || j > grid[0].size()-1 || visited[i][j] || grid[i][j] == '0') return;
        visited[i][j] = true;
        for (int k=0; k<4; k++) {
            dfs(i+x[k], j+y[k], grid, visited);
        }
    }

    int ff(vector<vector<char>>& grid) {
        if (!grid.size()) return 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int count = 0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j] == '1' and !visited[i][j]) {
                    dfs(i, j, grid, visited);
                    count++;
                }
            }
        }
        return count;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        return ff(grid);
    }
};
