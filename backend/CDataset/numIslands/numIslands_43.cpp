class Solution {
public:
int numIslands(vector<vector<char>>& grid) {
    if (grid.size() == 0) return 0;
    vector<vector<int>> cnt(grid.size(), vector<int>(grid[0].size(), 0));
    
    int max = 0;
    int dup = 0;
    map<int, int> mapping;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] == '1') {
                int a = (i == 0) ? 0: cnt[i-1][j]; 
                int b = (j == 0) ? 0: cnt[i][j-1];
                if (a == 0 && b == 0) {
                    max++;
                    cnt[i][j] = max;
                    mapping[max] = max;
                } else if (a == 0) { // b != 0
                    cnt[i][j] = b;
                } else if (b == 0) { // a != 0
                    cnt[i][j] = a;
                } else if (a == b) {
                    cnt[i][j] = a;
                } else { // both not zero and not equal
                    if (mapping[a] != mapping[b]) {
                        dup++;
                        if (mapping[a] > mapping[b]) {
                            remap(mapping, a, mapping[b]);
                        } else {
                            remap(mapping, b, mapping[a]);
                        }
                    }
                    cnt[i][j] = mapping[a];
                }
            }
        }
    }
    return max - dup;
}

void remap(map<int,int>& mapping, int key, int val) {
    mapping[mapping[key]] = val; // important
    mapping[key] = val;
} };