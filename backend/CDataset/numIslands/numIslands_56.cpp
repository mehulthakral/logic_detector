class Solution {
public:
    int nr_row, nr_col;
    const int TYPE_WATER = 0x7fffffff;
    int numIslands(vector<vector<char> > &grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        nr_row = grid.size();
        nr_col = grid[0].size();

        int type_num = 0;
        vector<int> type(nr_col + 1, TYPE_WATER); //type[k+1] => grid[x][k] type
        unordered_map<int, int> table;            //并查集, disjoint set
        for (int i = 0; i < nr_row; ++i) {
            for (int j = 0; j < nr_col; ++j) {
                int near_type = min(type[j], type[j+1]);
                if (grid[i][j] == '1') {
                    if (type[j] != TYPE_WATER && type[j+1] != TYPE_WATER) {
                        int group1 = find_parent(table, type[j]);
                        int group2 = find_parent(table, type[j+1]);
                        table[max(group1, group2)] = min(group1, group2);
                    }
                    if (near_type == TYPE_WATER) {
                        type[j+1] = ++type_num;
                        table[type[j+1]] = type[j+1];
                    } else {
                        type[j+1] = near_type;
                    }
                } else {
                    type[j+1] = TYPE_WATER;
                }
            }
        }

        unordered_set<int> s;
        for (int i = 1; i <= type_num; ++i) {
            s.insert(find_parent(table, i));
        }
        return s.size();
    }

    int find_parent(unordered_map<int, int> &table, int type) {
        return table[type] == type ? type :
                table[type] = find_parent(table, table[type]);
    }
};