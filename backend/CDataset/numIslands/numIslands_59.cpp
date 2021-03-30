class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (!grid.size() || !grid[0].size()) return 0;
        int count = 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<int> queue; 
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '0' || visited[i][j]) continue;
                count++;
                visited[i][j] = true;
                queue.push(i * n + j);
                while (!queue.empty()) {
                    int x = queue.front() / n, y = queue.front() % n;
                    queue.pop();
                    if (grid[x][y] == '0') continue;
                    if (x - 1 >= 0 && !visited[x-1][y]) {queue.push((x-1) * n + y); visited[x-1][y] = true;}
                    if (y - 1 >= 0 && !visited[x][y-1]) {queue.push(x * n + y-1); visited[x][y-1] = true;}
                    if (x + 1 < m && !visited[x+1][y]) {queue.push((x+1) * n + y); visited[x+1][y] = true;}
                    if (y + 1 < n && !visited[x][y+1]) {queue.push(x * n + y+1); visited[x][y+1] = true;}
                }
            }
                
        return count;           
    }

};