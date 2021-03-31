int numIslands(vector<vector<char>>& grid) {
  int N = grid.size();
  int count = 0;
  vector<int> parent(N ? N * grid[0].size() : 0);
  for (int r = 0; r < grid.size(); ++r) {
    for (int c = 0; c < grid[r].size(); ++c) {
      if (grid[r][c] == '1') {
        ++count;
        int i = idx(r, c, N);
        parent[i] = i;
        if (r > 0 && grid[r-1][c] == '1' && doUnion(i, idx(r-1, c, N), parent))
          --count;
        if (c > 0 && grid[r][c-1] == '1' && doUnion(i, idx(r, c-1, N), parent))
          --count;
      }
    }
  }
  return count;
}

bool doUnion(int x, int y, vector<int>& parent) {
  int rootx = find(x, parent);
  int rooty = find(y, parent);
  if (rootx == rooty)
      return false;
  parent[rooty] = rootx;
  return true;
}

int find(int x, vector<int>& parent) {
  return (parent[x] == x) ? x : find(parent[x], parent);
}

inline int idx(int row, int col, int nrows) { return col * nrows + row; }