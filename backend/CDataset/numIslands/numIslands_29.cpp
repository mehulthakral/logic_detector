class Solution {
public:
	int m;
	int n;
	void fill(vector<vector<char>>& grid,int x,int y){
		if(x<0 ||x>=m || y<0 || y>=n || grid[x][y]=='0'){
			return;
		}
		grid[x][y]='0';
		fill(grid,x+1,y);
		fill(grid,x-1,y);
		fill(grid,x,y+1);
		fill(grid,x,y-1);
	}
	int numIslands(vector<vector<char>>& grid) {
		if(grid.empty()) return 0;
		m=grid.size();
		n=grid[0].size();
		int res=0;
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(grid[i][j]=='1'){
					res++;
					fill(grid,i,j);
				}
			}
		}
		return res;

	}
};