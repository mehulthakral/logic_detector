class Solution {
public:
    int count=0;
    int numIslands(vector<vector<char>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        for (int i=0; i<row; i++) {
            for (int j=0; j<col; j++) {
                if (grid[i][j]=='1') count++, dfs (grid, i, j) ;
            }
        }
        return count;
    }
    void dfs (vector<vector<char>> &grid, int i, int j) {
        if (i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]!='1') return;
        grid[i][j]='0';
        vector <vector<int>> v={{0,1}, {1,0}, {-1,0}, {0,-1}};
        for (int x=0; x<4; x++) {
            dfs (grid, i+v[x][0], j+v[x][1]);
        }
    }
};
