class Solution {
private:
    unordered_map<int, vector<int> > graph;
    unordered_map<int, vector<int> > rgraph;
    vector<bool> visited;
    stack<int> st;
    
    void dfs1(int u) {
        if(visited[u]) {
            return;
        }
        
        visited[u] = true;
        for(int v: graph[u]) {
            dfs1(v);
        }
        
        st.push(u);
    }
    
    int dfs2(int u) {
        if(visited[u]) {
            return 0;
        }
        
        int count = 1;
        visited[u] = true;
        for(int v: rgraph[u]) {
            count += dfs2(v);
        }
        
        return count;
    }
    
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int u, v, count;
        
        visited = vector<bool>(numCourses, false);
        
        for(auto req: prerequisites) {
            u = req[1];
            v = req[0];
            graph[u].push_back(v);
            rgraph[v].push_back(u);
        }
        
        for(u=0; u<numCourses; u++) {
            if(visited[u] == false) {
                dfs1(u);
            }
        }
        
        visited = vector<bool>(numCourses, false);
        
        while(st.size()) {
            u = st.top();
            st.pop();
            if(visited[u] == false) {
                count = dfs2(u);
                if(count>1) {
                    return false;
                }
            }
        }
        
        return true;
    }
};