class Solution {
public:
    //bfs + iterative
    //time: o(row * column)
    //space: o(column)
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty())
            return 0;
        
        int count_of_islands = 0;
        for(int row = 0; row < grid.size(); ++row) {
            for(int col = 0; col < grid[0].size(); ++col) {
                if(grid[row][col] == '1') {
                    ++count_of_islands;
                    std::queue<pair<int, int>> bfs_que;//<row, column>
                    grid[row][col] = '2';
                    bfs_que.push(make_pair(row, col));
                    while(!bfs_que.empty()) {
                        std::pair<int, int> visited_node = bfs_que.front();
                        bfs_que.pop();
                        for(auto d : dir) {
                            int next_row = visited_node.first + d.first;
                            int next_col = visited_node.second + d.second;
                            if(next_row >= 0 && next_row < grid.size() && next_col >= 0 && next_col < grid[0].size() && grid[next_row][next_col] == '1') {
                                grid[next_row][next_col] = '2';
                                bfs_que.push(make_pair(next_row, next_col));
                            }
                            
                        }
                    }
                }   
            }  
        }
        return count_of_islands;
    }

private:
    vector<pair<int, int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};//<row, column>
};