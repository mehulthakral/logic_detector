class Solution {
    void sinkIsland(int x, int y, vector<vector<char>>& grid) {
        if (x < 0 || y < 0 || x == grid.size()  || y == grid[0].size()) return; // Return if we are out of bounds
        if (grid[x][y] == '0') return; // return if we hit the ocean
        grid[x][y] = '0'; // Otherwise, we didn't hit the ocean, time to sink the island
        sinkIsland(x + 1, y, grid); // Go down one 
        sinkIsland(x - 1, y, grid); // Go up one
        sinkIsland(x, y + 1, grid);  // Go right one
        sinkIsland(x, y - 1, grid); // go left one.
        return; // Island is sunk. Return to main function.
    }
      
public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt{};
        if (grid.empty()) return 0;
        for (int i{}; i < grid.size(); i++) {
            for (int j{}; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') { // If there is a 1, it's an island, lets wipe it off the map.
                    sinkIsland(i, j, grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};