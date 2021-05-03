class Solution {
public:
    //dfs + recursive
    //time: o(row * column)
    //space: o(row)
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty())
            return 0;
        
        int count_of_islands = 0;
        for(int row = 0; row < grid.size(); ++row) {
            for(int col = 0; col < grid[0].size(); ++col) {
                if(grid[row][col] == '1') {
                    ++count_of_islands;
                    dfs(grid, row, col);//use dfs to mark every grid = 2 which belongs to this island.
                }   
            }  
        }
        return count_of_islands;
    }
private:
    //dfs to mark every grid in this island.
    int dfs(vector<vector<char>>& grid, int row, int col) {
        grid[row][col] = '2';
        for(auto d : dir) {
            int next_row = row + d.first;
            int next_col = col + d.second;
            if(next_row >= 0 && next_row < grid.size() && next_col >= 0 && next_col < grid[0].size() && grid[next_row][next_col] == '1') {
                dfs(grid, next_row, next_col);
            }   
        }
        return 0;
    }
private:
    vector<pair<int, int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};//<row, column>
};