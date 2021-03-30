class Solution {
public:
    int maxX, maxY, res = 0;
    void dfs(vector<vector<char>>& grid, int x, int y) {
	    // checking if we are out of bounds
        if (x < 0 || x == maxX || y < 0 || y == maxY) return;
        char &currCell = grid[y][x];
        if (currCell != '1') return;
        // we mark it as visited
        currCell = '#';
        // exploring right, left, down, up
        dfs(grid, x + 1, y);
        dfs(grid, x - 1, y);
        dfs(grid, x, y + 1);
        dfs(grid, x, y - 1);
    }
    int numIslands(vector<vector<char>>& grid) {
        maxY = grid.size();
        // exit condition for empty map
        if (!maxY) return res;
        maxX = grid[0].size();
        for (int y = 0; y < maxY; y++) {
            for (int x = 0; x < maxX; x++) {
                if (grid[y][x] == '1') {
                    // oh, we found an island!
                    res++;
                    // then we need to mark all the tiles on that island as visited!
                    dfs(grid, x, y);
                }
            }
        }
        return res;
    }
};