class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        if (row == 0)
            return 0;
        int col = grid[0].size();
        if (col == 0)
            return 0;

        vector<vector<int>> visited(row, vector<int>(col, 0));
        
        int count = 0;
        int i = 0;
        int j = 0;
        
        for (i = 0; i < row; i++)
        {
            for (j = 0; j < col; j++)
            {
                if ( (visited[i][j] == 0) && (grid[i][j] == '1') )
                {
                    count++;
                    dfs(grid, visited, i, j, row, col);
                }
            }
        }
        
        return count;
    }
    
    void dfs(vector<vector<char>> &grid, vector<vector<int>> &visited, int i, int j, int row, int col)
    {
        if (i < 0 || i >= row || j < 0 || j >= col)
            return;
        
        if (grid[i][j] == '0' || visited[i][j] == 1)//water or has been visited
            return;
            
        visited[i][j] = 1;
        
        dfs(grid, visited, i-1, j, row, col);//up
        dfs(grid, visited, i, j+1, row, col);//right
        dfs(grid, visited, i+1, j, row, col);//down
        dfs(grid, visited, i, j-1, row, col);//left
    }
};