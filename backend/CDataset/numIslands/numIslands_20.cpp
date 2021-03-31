class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int island_count = 0;
        
		// iterate through the matrix O(m x n)
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == '1') {
					// found an island, increment count and call sink
                    ++island_count;
                    sinkIsland(&grid, i, j);
                }
            }
        }
        
        return island_count;
    }
private:
    void sinkIsland(vector<vector<char>>* grid_ptr, int i, int j) {
		// passing by pointer to avoid using non-const references
		// this is a C++ style choice
        auto& grid = *grid_ptr;
        
		// if the current coordinate isn't part of the island, return
        if (grid[i][j] != '1') return;
        
		// sink the current coordinate
        grid[i][j] = '0';
        
		// if the any of the following coordinates is valid
		// call sinkIsland recursively
		if (i < grid.size() - 1) sinkIsland(grid_ptr, i + 1, j);  // east
        if (i > 0) sinkIsland(grid_ptr, i - 1, j);  // west
		if (j < grid[i].size() - 1) sinkIsland(grid_ptr, i, j + 1);  // north
        if (j > 0) sinkIsland(grid_ptr, i, j - 1);  // south
    }
};
