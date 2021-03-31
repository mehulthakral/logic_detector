class Solution {
public:
    
    void DepthFirstSearch(vector<vector<char>> &grid, int r, int c){
        int Rows = grid.size();
        int Columns = grid[0].size();
        
        grid[r][c] = '0';
        
        if (r+1 <  Rows    && grid[r+1][c] == '1') DepthFirstSearch(grid, r+1, c); //visit uper
        if (r-1 >= 0       && grid[r-1][c] == '1') DepthFirstSearch(grid, r-1, c); //visit lower 
        if (c+1 <  Columns && grid[r][c+1] == '1') DepthFirstSearch(grid, r, c+1); //visit right
        if (c-1 >= 0       && grid[r][c-1] == '1') DepthFirstSearch(grid, r, c-1); //visit left
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int numberOfIslands = 0;
        int Rows = grid.size();
        if (Rows == 0) return 0;
        int Columns = grid[0].size();
        
        for (int iI = 0; iI < Rows; iI++){
            for (int iJ = 0; iJ < Columns; iJ++){
                if (grid[iI][iJ] == '1'){
                    numberOfIslands++;
                    DepthFirstSearch(grid, iI, iJ);
                }
            }
        }
        
        return numberOfIslands;
    }
};