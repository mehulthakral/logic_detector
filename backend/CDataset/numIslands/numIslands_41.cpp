class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
    const int row = grid.size();
    if (0 == row) return 0;
    const int col = grid[0].size();
    int cnt = 0;
    for (int i = 0; i < row; i++)
     for (int j = 0; j < col; j++) {
         if (grid[i][j] == '1') {
             cnt++;
             dfs(grid, i, j);
         }
     }
     return cnt;
}
void dfs(vector<vector<char>> &grid, int i, int j) {
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != '1') return;
    grid[i][j] = '2';
    vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    for (auto dir : dirs) dfs(grid, i + dir.first, j + dir.second);
}
};