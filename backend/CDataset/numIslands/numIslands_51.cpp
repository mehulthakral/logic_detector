typedef pair<int, int> pii;

class Solution {
public:
    void makeSet(pii x, map<pii, pair<pii, int>>& m, int& cnt){
        m.insert(make_pair(x, make_pair(x, 0)));
        cnt++;
    }
    
    pii findSet(pii x, map<pii, pair<pii, int>>& m){
        if(m[x].first == x) return x;
        else{
            m[x].first = findSet(m[x].first, m);
            return m[x].first; 
        }
    }
    
    void unionSet(pii x, pii y, map<pii, pair<pii, int>>& m, int& cnt){
        pii parX = findSet(x, m);
        pii parY = findSet(y, m);
        if(parX == parY) return;
        
        int rankX = m[parX].second; 
        int rankY = m[parY].second;
        if(rankX < rankY) m[parX].first = parY;
        else m[parY].first = parX;
        
        if(rankX == rankY) m[parX].second += 1; 
        cnt--; 
    }
    
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0) return 0;
        int rows = grid.size(), cols = grid[0].size();
        map<pii, pair<pii, int>> m; // map to parent & rank
        int cnt = 0; // counter for sets
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == '1') makeSet(make_pair(i, j), m, cnt);
            }
        }
        int x = 0, y = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == '1'){
                    // explore four directions
                    x = i - 1;
                    y = j;
                    if(x >= 0 && grid[x][y] == '1')
                        unionSet(make_pair(i, j), make_pair(x, y), m, cnt);
                    x = i + 1;
                    if(x < rows && grid[x][y] == '1')
                        unionSet(make_pair(i, j), make_pair(x, y), m, cnt);
                    x = i;
                    y = j - 1;
                    if(y >= 0 && grid[x][y] == '1')
                        unionSet(make_pair(i, j), make_pair(x, y), m, cnt);
                    y = j + 1;
                    if(y < cols && grid[x][y] == '1')
                        unionSet(make_pair(i, j), make_pair(x, y), m, cnt);
                }
            }
        }
        return cnt;
    }
};