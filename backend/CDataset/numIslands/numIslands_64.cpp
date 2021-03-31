class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        int m = grid.size();
        if (m==0) return 0;
        int n = grid[0].size();
        int count = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]=='1') {
                    helper(grid,i,j,m,n);
                    count++;
                }
            }
        }
        return count;
    }
    
    void helper(vector<vector<char> >& a, int i, int j, int m, int n) {
        a[i][j] = 0;
        if (i > 0 && a[i-1][j]=='1') helper(a,i-1,j,m,n);
        if (j > 0 && a[i][j-1]=='1') helper(a,i,j-1,m,n);
        if (i < m-1 && a[i+1][j]=='1') helper(a,i+1,j,m,n);
        if (j < n-1 && a[i][j+1]=='1') helper(a,i,j+1,m,n);
    }
};