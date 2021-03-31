class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        queue<pair<int, int>> q;
        set<pair<int, int>> vis;
        int no_isl = 0;
        
        for(int row = 0; row < grid.size(); row++)
        {
            for(int col = 0; col < grid[row].size(); col++)
            {
                if(grid[row][col] == '1' && vis.find({row, col}) == vis.end())
                {
                    q.push({row, col});
                    vis.insert({row, col});
                    while(!q.empty())
                    {
                        pair<int, int> front = q.front();
                        q.pop();
                        int r = front.first, c = front.second, rsize = grid.size(), csize = grid[row].size();
                        
                        if(c+1 < csize && grid[r][c+1] == '1' && vis.find({r, c+1}) == vis.end())
                        {
                            q.push({r, c+1});
                            vis.insert({r, c+1});
                        }
                        if(r+1 < rsize && grid[r+1][c] == '1' && vis.find({r+1, c}) == vis.end())
                        {
                            q.push({r+1,c});
                            vis.insert({r+1, c});
                        }
                        if(c-1 >= 0 && grid[r][c-1] == '1' && vis.find({r,c-1}) == vis.end())
                        {
                            q.push({r, c-1});
                            vis.insert({r, c-1});
                        }
                        if(r-1 >= 0 && grid[r-1][c] == '1' && vis.find({r-1, c}) == vis.end())
                        {
                            q.push({r-1,c});
                            vis.insert({r-1, c});
                        }   
                    }
                    no_isl += 1;
                }
            }
        }
        return no_isl;
    }
};
