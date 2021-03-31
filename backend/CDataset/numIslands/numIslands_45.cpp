class Solution 
{
    int m,n, cc = 0;
    bool vis[1001][1001];
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

public:
    bool isValid(vector> &grid, int x, int y)
    {
        m = grid.size(), n = grid[0].size();
        if (x < 0 || x >= m || y < 0 || y >= n)
            return false;

        if (vis[x][y] == true || grid[x][y] == '0')
            return false;

        return true;
    }

    void dfs(vector> &grid, int x, int y)
    {
        vis[x][y] = true;

        for (int i = 0; i < 4; i++)
            if (isValid(grid, x + dx[i], y + dy[i]))
                dfs(grid, x + dx[i], y + dy[i]);
    }

    int numIslands(vector> &grid)
    {
        m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                if (vis[i][j] == false && grid[i][j] == '1')
                    dfs(grid, i, j), cc++;
        }

        return cc;
    }
};