class UnionFind {
private:
    vector<int> parent;

public:
    int count;

    UnionFind(int n) : parent(n), count(n) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    void uni(int p, int q) {
        int pRoot = find(p);
        int qRoot = find(q);
        if (pRoot != qRoot) {
            parent[pRoot] = qRoot;
            count--;
        }
    }

    int find(int node) {
        if (parent[node] == node) {
            return node;
        }
        //path compression
        parent[node] = find(parent[node]);
        return parent[node];
    }

    bool connected(int p, int q) {
        return find(p) == find(q);
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        if (grid.empty()) return 0;
        int d[2][2]{{1, 0},
                    {0, 1}};  //search right/down.
        int m = grid.size(), n = grid[0].size(), zeros = 0;
        UnionFind uf(m * n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != '1') {
                    zeros++;
                    continue;
                }
                int node1 = i * n + j;
                for (int k = 0; k < 2; k++) {
                    int newX = i + d[k][0];
                    int newY = j + d[k][1];
                    if (newX >= 0 && newX < m && newY >= 0 && newY < n && grid[newX][newY] == '1') {
                        int node2 = newX * n + newY;
                        uf.uni(node1, node2);
                    }
                }
            }
        }
        return uf.count - zeros;
    }
};
