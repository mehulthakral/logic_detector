class Solution {
public:
    void helper(vector<vector<char>>& grid,int x,int y,int n,int m){
        if(x<0|| x>=n || y<0 || y>=m || grid[x][y]=='0' ) return;
        grid[x][y]='0'; //mark node as visited
        helper(grid,x-1,y,n,m);
        helper(grid,x+1,y,n,m);
        helper(grid,x,y+1,n,m);
        helper(grid,x,y-1,n,m);
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        int n=grid.size();
        
        for(int i=0;i<n;i++){
            int m=grid[i].size();
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    ans++;
                    helper(grid,i,j,n,m);
                }
            }
        }
        return ans;
    }
};
