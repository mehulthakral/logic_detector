class Solution {
private:
    int row, column;
    void traverse(vector<vector<char>>& grid, int r, int c)
    {
        grid[r][c] = '0';
        if(r-1>-1 && grid[r-1][c]=='1') traverse(grid, r-1, c);
        if(c-1>-1 && grid[r][c-1]=='1') traverse(grid, r, c-1);
        if(r+1<row && grid[r+1][c]=='1') traverse(grid, r+1, c);
        if(c+1<column && grid[r][c+1]=='1') traverse(grid, r, c+1); 
        
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        row=grid.size();
        if(!row) return 0;
        column=grid[0].size();
        int count = 0;
        for(int r = 0; r < row; r++)
            for(int c = 0; c < column; c++)
                if(grid[r][c] == '1') count++,traverse(grid, r, c);
        return count;
    }
};