class Solution {
public:
    struct Point {
        int row, col;
        Point(int _x, int _y) : row(_x), col(_y) {}
    };
    int nr_row, nr_col;
    int numIslands(vector<vector<char> > &grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }

        nr_row = grid.size();
        nr_col = grid[0].size();

        int res = 0;
        queue<Point> q;
        
        for (int i = 0; i < nr_row; ++i) {
            for (int j = 0; j < nr_col; ++j) {
                if (grid[i][j] == '0') {
                    continue;
                }
                ++res;

                grid[i][j] = '0';
                q.push(Point(i, j));
                while (!q.empty()) {
                    Point point = q.front();
                    q.pop();
                    addNeighbor(grid, point, -1,  0, q);
                    addNeighbor(grid, point,  0, -1, q);
                    addNeighbor(grid, point,  1,  0, q);
                    addNeighbor(grid, point,  0,  1, q);
                }
            }
        }
        return res;
    }

    void addNeighbor(vector<vector<char> > &grid, Point point, 
            int d_row, int d_col, queue<Point> &q) {
        point.row += d_row;
        point.col += d_col;
        if (point.row >= nr_row || point.col >= nr_col || 
                point.row < 0 || point.col < 0 ||
                grid[point.row][point.col] == '0') {
            return;
        }
        grid[point.row][point.col] = '0';

        q.push(point);
    }
};