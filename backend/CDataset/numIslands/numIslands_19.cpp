#define fastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
class Solution {
public:
int r,c;
int isl=0;
void markcurr(vector<vector<char>>& grid , int x,int y){
    if(x<0 || x>=r || y<0 || y>=c || grid[x][y]!='1')return ;
    grid[x][y]='2';
    
    markcurr(grid,x+1,y);
    markcurr(grid,x-1,y);
    markcurr(grid,x,y+1);
    markcurr(grid,x,y-1);
}
int numIslands(vector<vector<char>>& grid) {
    fastIO;
    r=grid.size();
    if(r==0)return 0;
    c=grid[0].size();
    
    for(int i=0;i<r;++i)
        for(int j=0;j<c;++j)
            if(grid[i][j]=='1')
                {markcurr(grid,i,j);
                isl++;}
                
    return isl;
}
