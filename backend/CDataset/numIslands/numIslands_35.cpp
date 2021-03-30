class UF
{
public:
	UF(int n) :id(n), sz(n, 1), counter(n)
	{
		for (int i = 0; i < n; ++i) id[i] = i;
	}

	void uni(int p, int q)
	{
		int i = root(p);
		int j = root(q);
		if (i != j)
		{
			if (sz[i] < sz[j]) {
				id[i] = j;
				sz[j] += sz[i];
			}
			else{
				id[j] = i;
				sz[i] += sz[j];
			}
			--counter;
		}
	}

	int root(int i)
	{
		while (i != id[i])
		{
			id[i] = id[id[i]];
			i = id[i];
		}
		return i;
	}

	bool connected(int p, int q)
	{
		return root(p) == root(q);
	}

	int count(){
		return counter;
	}
private:
	int counter;
	vector<int> id;
	vector<int> sz;
};
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        if(rows == 0) return 0;
        int cols = grid[0].size();
        if(cols == 0) return 0;
        int n = rows * cols;
        int zeros = 0;
        UF uf(n);
        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < cols; ++j){
                if(grid[i][j] == '1'){
                    int id = i*cols + j;
                    if(i+1<=rows-1 && grid[i+1][j] == '1'){
                        uf.uni(id, id + cols);
                    }
                    if(j+1<=cols-1 && grid[i][j+1] == '1'){
                        uf.uni(id, id + 1);
                    }
                }
                else
                {
                    ++zeros;
                }
            }
        }
        return uf.count() - zeros;
    }
};