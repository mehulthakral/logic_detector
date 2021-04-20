class Solution {
public:bool dfs(vector<vector<int>> & a, vector<int> & v, int i)
{
	if(v[i]==1)  return true;
	if(v[i]==-1) return false;
	v[i] = -1;

	auto out{true};
	for(const auto & k : a[i]) out &= dfs(a, v, k);

	v[i] = 1;
	return out;
}

bool canFinish(int n, vector<vector<int>>& p)
{
	vector a(n, vector<int>{});
	for(const auto & i : p) a[i[0]].push_back(i[1]);

	vector v(n, 0);
	auto out{true};
	for(auto i{0}; i<n; ++i)
		out &= dfs(a, v, i);

	return out;
}
};