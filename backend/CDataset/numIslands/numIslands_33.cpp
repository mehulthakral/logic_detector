class Solution {
public:
    
    void dfs(vector<vector<char>>& graph,int row,int col){

    if(graph[row][col] == '1'){
        graph[row][col] = '0';
    if(row >=1)
        dfs(graph,row-1,col);
    if(row <graph.size()-1)
        dfs(graph,row+1,col);
    if(col >= 1)
        dfs(graph,row,col-1);
    if(col < graph[0].size()-1)
        dfs(graph,row,col+1);
    }

}
    
    
    int numIslands(vector<vector<char>>& grid) {
            int ans = 0;
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            if(grid[i][j] == '1'){
                dfs(grid,i,j);
                ans++;
            }
        }
    }
    return ans;
    }
};
