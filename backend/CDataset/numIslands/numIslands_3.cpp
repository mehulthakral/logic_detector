class Solution {
public:
    #include<vector>
    class UnionFind{
public:
    int n, m;   
    vector < vector <int> > size;
    vector <vector <pair <int, int> > > parent;
    vector < vector <bool> > cross;
    int numofcomponents;
    UnionFind(int n, int m) {
        this->n = n;
        this->m = m;
        size.assign(n, vector <int> (m, 1));
        cross.assign(n, vector <bool> (m, true));
        parent.assign(n, vector <pair <int, int> > (m, {-1, -1}));
        for (int i = 0; i < n; i++) { for (int j = 0; j < m; j++) {parent[i][j] = {i, j};} }
        numofcomponents = n*m;
    }

    pair <int, int> find(pair <int, int> p) {
        pair <int, int> root = p;
        while (root != parent[root.first][root.second]) {
            root =  parent[root.first][root.second];
        }
        // Armortized Algorithm
        while (p != root) {
            pair <int, int> next = parent[p.first][p.second];
            parent[p.first][p.second] = root;
            p = next;
        }
        return root;
    }

    bool isConnected(pair <int, int> p, pair <int, int> q) {
        return find(p) == find(q);
    }

    int componentsize(pair <int, int> p ) {
        pair <int, int> temp = find(p);
        return size[temp.first][temp.second];
    }

    int commponents() {
        return numofcomponents;
    }

    void unify(pair <int, int> p, pair <int, int> q) {
        pair <int, int> root1 = find(p);
        pair <int, int> root2 = find(q);
        if (root1 == root2) return;
        if (size[root1.first][root1.second] > size[root2.first][root2.second]) {
            size[root1.first][root1.second] += size[root2.first][root2.second];
            parent[root2.first][root2.second] = root1;
        } else {
            size[root2.first][root2.second] += size[root1.first][root2.second];
            parent[root1.first][root1.second] = root2;
        }

        numofcomponents--;
    }
};
    int numIslands(vector<vector<char>>& grid) {
         int n = grid.size();
        if (n == 0)return 0;
        int zeros = 0;
        int m = grid[0].size();
        UnionFind U(n, m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '0') {
                    zeros++;
                    continue;
                }
                if (i != 0) {
                    if (grid[i][j] == grid[i - 1][j])
                    U.unify({i, j},{i - 1, j});
                }
                if (j != 0) {
                     if (grid[i][j] == grid[i][j - 1])
                    U.unify({i, j}, {i, j - 1});
                }
                if (i != n - 1) {
                    if (grid[i][j] == grid[i + 1][j])
                    U.unify({i, j}, {i + 1, j});
                }
                if (j != m - 1) {
                     if (grid[i][j] == grid[i][j + 1])
                    U.unify({i, j}, {i, j + 1});
                }
                if (i == 0 || j == 0 || i == n - 1 || j == m-1) {
                    pair <int, int> tmp = U.find({i, j});
                    U.cross[tmp.first][tmp.second] = false;
                }
               
            }
        }
        return U.numofcomponents - zeros;

    }
};

