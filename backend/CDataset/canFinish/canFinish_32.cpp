class Solution {
	private:
	vector<vector<int>> graph;
	vector<int> dp;
public:
	bool dfs(int a){
		if(dp[a]==1) return true;
		if(dp[a]==2) return false;
		dp[a]=1;
		for(auto v:graph[a]){
			if(dfs(v)){
				return true;
			}
		}
		dp[a]=2;
		return false;
	}
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		if(prerequisites.size()==0) return true;
		graph=vector<vector<int>>(numCourses);
		for(auto x:prerequisites){
			graph[x[1]].push_back(x[0]);

		}
		dp=vector<int>(numCourses,0);
		for(int i=0;i<numCourses;i++){
			if(dfs(i)){
				return false;
			}
		}
		return true;

	}
};