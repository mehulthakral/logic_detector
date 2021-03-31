class Solution {
public:
    bool isCyclic(int v, vector<bool> &vis, vector<bool>&rec, vector<vector<int>>&Adj){
        vis[v] = true;
        rec[v] = true;
        for (auto x: Adj[v]){
            if (rec[x])
                return true; // means we have a back edge here
            else if (!vis[x] and isCyclic(x, vis,rec, Adj))
                return true; // means we found a back edge in one of the descendants of this node
        }
        rec[v] = false;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> Adj(n);
        for (auto x: prerequisites){
            Adj[x[0]].push_back(x[1]);
        }
        vector<bool> visited(n,false);
        vector<bool> recStack(n,false);
        for (int i =0; i < n; i++){
            if (!visited[i])
                if (isCyclic(i,visited,recStack, Adj))
                    return false;
        }
        return true;
    }
};