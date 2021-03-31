int numIslands(vector<vector<char>>& grid) {
        int label = 0;
        int rowNum = grid.size(), colNum = rowNum ? grid[0].size() : 0;
        
        for (int i = 0; i < rowNum; ++i) {
            for (int j = 0; j < colNum; ++j) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j, rowNum, colNum);
                    ++label;
                }
            }
        }
        
        return label;
    }
    
    void dfs(vector<vector<char>>& grid, int row, int col, 
                      int& rowNum, int& colNum) {
        if (row < 0 || col < 0 || row >= rowNum || col >= colNum || grid[row][col] == '0') return;
        
        grid[row][col] = '0';
        dfs(grid, row + 1, col, colNum, rowNum);
        dfs(grid, row - 1, col, colNum, rowNum);
        dfs(grid, row, col + 1, colNum, rowNum);
        dfs(grid, row, col - 1, colNum, rowNum);
    }