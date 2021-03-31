class Solution {
public:
bool canFinish(int n, vector<vector>& prerequisites) {

    if(n==0) return true;
    vector<int> adj[n];
    vector<int> indeg(n,0);
    for(auto pre :prerequisites ){
        adj[pre[1]].push_back(pre[0]);
        indeg[pre[0]]++;
    }
    int c=0;
    queue<int> q;
    for(int i=0;i<n;i++){
        if(indeg[i]==0) q.push(i);
    }
    while(!q.empty()) {
        int u=q.front(); q.pop();
        c++;
        for(auto v : adj[u]){
            indeg[v]--;
            if(indeg[v]==0) q.push(v);
        }
    }
    return (c==n);
}
};