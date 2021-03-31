class Solution {
public:
    bool DFS(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0')
            return false;
        grid[i][j] = '0';
        vector<pair<int, int>> dirs = {{-1,0}, {0,-1}, {1,0}, {0,1}};
        for (auto dir : dirs) {
            DFS(grid, i + dir.first, j + dir.second);
        }
        return true;
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (DFS(grid, i, j))
                    ans++;
            }
        }
        return ans;
    }
};