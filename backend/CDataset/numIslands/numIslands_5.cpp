class Solution {
public:
   //make as visited as you traverse by making it "0"(change from land to water)
    void bfs(vector<vector<char>>& grid, int i, int j, int n, int m){
        grid[i][j] = '0';
        
        if(i-1 >= 0 && grid[i-1][j] == '1') //up
            bfs(grid, i-1, j, n, m);
        if(i+1 < n && grid[i+1][j] == '1') //down
            bfs(grid, i+1, j, n, m);
        if(j+1 < m && grid[i][j+1] == '1') //right
            bfs(grid, i, j+1, n, m);
        if(j-1 >= 0 && grid[i][j-1] == '1') //left
            bfs(grid, i, j-1, n, m);
    }
        
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1'){
                    bfs(grid, i, j , n, m);
                    count++;
                }    
            }
        }
        return count;
    }
};
