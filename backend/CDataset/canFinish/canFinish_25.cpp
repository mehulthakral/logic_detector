class Solution {
public:
    //TOPOLOGICAL SORT USING BFS
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(n,vector<int>());
        queue<int> q;
        vector<int> in_degree(n,0);
        vector<int> ans;
        //Making graph edge is unidirictional(p[1] --> p[0]) 
        for(auto p: prerequisites) {
            graph[p[1]].push_back(p[0]);
            ++in_degree[p[0]];
        }
        //Push all the elements in the queue which has 0 in_degree
        for(int i=0;i<n;++i) {
            if(in_degree[i]==0) {
                q.push(i);
            }
        }
        //if we remove the parent of a node then its in_degree will decreases by 1 unit
        while(!q.empty()) {
            int cur=q.front();
            q.pop();
            ans.push_back(cur);
            for(int child: graph[cur]) {
                --in_degree[child];
                if(in_degree[child]==0) {
                    q.push(child);
                }
            }
        }
        return ans.size()==n;
    }
};
