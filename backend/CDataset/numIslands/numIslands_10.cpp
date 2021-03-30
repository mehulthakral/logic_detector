// Logic to this solution: recursively erase all found islands.
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    eraseIsland(i, j, grid);
                    count++;
                }
            }
        }
        return count;
    }
    void eraseIsland(int i, int j, vector<vector<char>>& grid) {
        if (0 <= i && i < grid.size() && 0 <= j && j < grid[i].size() && grid[i][j] == '1') {
            grid[i][j] = '0';
            eraseIsland(i - 1, j, grid);
            eraseIsland(i, j - 1, grid);
            eraseIsland(i + 1, j, grid);
            eraseIsland(i, j + 1, grid);
        }
    }
};
