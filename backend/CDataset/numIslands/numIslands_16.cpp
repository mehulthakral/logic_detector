class Solution {
private:
    const vector<vector<int>> DIR {{1,0}, {-1,0}, {0,1}, {0,-1}};
    
    bool isSafe(const vector<vector<char>>& grid, int x, int y) {
        return x >= 0 and x < grid.size() and y >= 0 and y < grid[0].size() and grid[x][y] == '1';
    }
    
    void markBfs(vector<vector<char>>& grid, int x, int y) {
        queue<array<int, 2>> q;
        q.push({x, y});
        while (!q.empty()) {
            auto current = q.front(); q.pop();
            for (const vector<int>& d : DIR) {
                int i = d[0] + current[0];
                int j = d[1] + current[1];
                if (isSafe(grid, i, j)) {
                    grid[i][j] = '0';
                    q.push({i, j});
                }
            }
        }
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    markBfs(grid, i, j);
                    islands++;
                }
            }
        }
        return islands;
    }
};
