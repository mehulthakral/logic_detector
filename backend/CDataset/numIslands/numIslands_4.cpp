class Solution {
public:
int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    count++;
                    depthFirstSearch(grid, i, j);
                }
            }
        }
        return count;
    }
    
    void depthFirstSearch(vector<vector<char>>& grid, int x, int y)
    {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size())
            return;
        if (grid[x][y] == '0')
            return;
        if (grid[x][y] == '1')
        {
            grid[x][y] = '0';
            depthFirstSearch(grid, x + 1, y);
            depthFirstSearch(grid, x - 1, y);
            depthFirstSearch(grid, x, y + 1);
            depthFirstSearch(grid, x, y - 1);
        }
    }
};