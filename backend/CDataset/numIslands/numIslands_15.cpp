class Solution {
public:
    void getnumislands(vector<vector<char>>& grid, int i, int j)
    {
        if(i<0 || i>=grid.size()) return;
        if(j<0 || j>=grid[0].size()) return;
        if(grid[i][j]=='0' || grid[i][j]=='2') return;
            
        grid[i][j]='2';
        
        getnumislands(grid,i+1,j);
        getnumislands(grid,i,j+1);
        getnumislands(grid,i-1,j);
        getnumislands(grid,i,j-1);
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {
                if(grid[i][j]=='1')
                {
                    getnumislands(grid,i,j);
                    count++;
                }
            }
        }
        
        return count;
    }
};
