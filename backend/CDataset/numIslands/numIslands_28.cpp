class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        //test edge cases
        if(grid.size()==0) return 0;
        int numIslands = 0;
        //lets traverse the matrix now and check for every cell
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {
                if(grid[i][j] == '1')
                {
                    numIslands += dfs(grid, i, j);
                }
            }
        }
        return numIslands;
    }
    
    int dfs(vector<vector<char>>& grid, int i, int j) {
        //check the bounds of 2-d matrix
        //it shouldn't go out of bounds i.e beyond the scope of matrix
        //And if grid[i][j] is 0 then we don't care and only return 0
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]=='0') 
            return 0;
        
        //since we have visited grid[i][j] lets mark it as 0 to avoid visiting it again
        grid[i][j]='0';
        //now lets traverse its neighbours 
        dfs(grid, i+1, j); //down
        dfs(grid, i-1, j); //up
        dfs(grid, i, j+1); //right
        dfs(grid, i, j-1); //left
        return 1;
    }    
};
