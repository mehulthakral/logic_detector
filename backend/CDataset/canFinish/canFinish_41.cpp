class Solution {
    using vi  = vector<int>;
public:
    template <typename Tmp, typename Tv>
    bool iscycle(Tmp& adj, Tv& vis, int id){
        if (vis[id] == 1) return true;
        if (vis[id] == 0) {
            vis[id]=1;
            for (auto& edge : adj[id])
                if (iscycle(adj,vis,edge)) return true;
        }
        vis[id] = 2;
        return false;
    }
    
    bool canFinish(int n, vector<vector<int>>& pre) {
        unordered_map<int, vi> adj;
        for(auto edge : pre)
            adj[edge[1]].push_back(edge[0]);
        
        vi vis(n, 0);
        for (const auto& pr : adj)
            if(iscycle(adj,vis, pr.first)) return false;
        return true;
    }
};