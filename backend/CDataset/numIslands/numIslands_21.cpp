class Solution {
private:
    void dfs(int i, int j, const vector<vector<char>>& grid, set<pair<int, int>>& vis, int n, int m){
        if( (i < 0 || j < 0 || i >= n || j >= m) ) return;
        vis.insert({i,j});
        if(grid[i][j] == '0') return;
        auto p = vis.find({i+1, j});
        if(p == vis.end()){
            dfs(i+1, j, grid, vis, n, m);
        }
        p = vis.find({i-1, j});
        if(p == vis.end()){
            dfs(i-1, j, grid, vis, n, m);
        }
        p = vis.find({i, j+1});
        if(p == vis.end()){
            dfs(i, j+1, grid, vis, n, m);
        }
        p = vis.find({i, j-1});
        if(p == vis.end()){
            dfs(i, j-1, grid, vis, n, m);
        }
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if(!n) return 0;
        int m = grid[0].size();
        if(!m) return 0;
        int cnt = 0;
        set<pair<int, int>> vis;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                auto p = vis.find({i, j});
                if(grid[i][j] == '1' && p == vis.end()){
                    dfs(i, j, grid, vis, n, m);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};