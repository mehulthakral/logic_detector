class Solution {
    unordered_map<int,vector<int> > gr;
public:
    bool iscyc(vector<int> &rec,vector<int> &vis,int u){
        if(!vis[u]){
            vis[u]=1;
            rec[u]=1;
            for(auto v:gr[u]){
                if(!vis[v] && iscyc(rec,vis,v)){
                    return true;
                }
                else if(rec[v]==1){
                    return true;
                }
            }
        }
        rec[u]=0;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& pr) {
        for(auto p:pr){
            gr[p[1]].push_back(p[0]);
        }
        vector<int> recs(n+1,0);
        vector<int> vis(n+1,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
            if(iscyc(recs,vis,i)){
                return false;
            }
            }
        }
        return true;
    }
};
