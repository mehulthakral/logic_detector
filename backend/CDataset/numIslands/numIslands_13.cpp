class Solution {
public:
    void dfs(vector<vector<char>>& grid,int i,int j,int r,int c)
    {   if(i<0||j<0||i>=r||j>=c||grid[i][j]!='1') return;
        grid[i][j]='2';
        dfs(grid,i-1,j,r,c);
        dfs(grid,i+1,j,r,c);
        dfs(grid,i,j-1,r,c);
        dfs(grid,i,j+1,r,c);
    }
    int numIslands(vector<vector<char>>& grid) {
        int r=grid.size();
        if(grid.size()==0)
            return 0;
        int c=grid[0].size();
        int ans=0;
        for(int i=0;i<r;i++)
        {  for(int j=0;j<c;j++)
            {   if(grid[i][j]=='1')
                {   dfs(grid,i,j,r,c);
                    ans++;
                }
            }
        }
        return ans;
    }
};
