class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0){
            return 0;
        }
        int m = grid.size();
        int n = grid[0].size();
        int ret = 0;
        stack<pair<int, int>> s;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    ret++;
                    s.push(make_pair(i, j));
                    while(!s.empty()){
                        pair<int, int> cur = s.top();
                        s.pop();
                        int x = cur.first;
                        int y = cur.second;
                        visited[x][y] = true;
                        if((x+1) < m && grid[x+1][y] == '1' && !visited[x+1][y]){
                            s.push(make_pair(x+1, y));
                        }
                        if((x-1) >=0 && grid[x-1][y] == '1' && !visited[x-1][y]){
                            s.push(make_pair(x-1, y));
                        }
                        if((y+1) < n && grid[x][y+1] == '1' && !visited[x][y+1]){
                            s.push(make_pair(x, y+1));
                        }
                        if((y-1) >= 0 && grid[x][y-1] == '1' && !visited[x][y-1]){
                            s.push(make_pair(x, y-1));
                        }
                    }
                }
            }
        }
        return ret;
    }
};