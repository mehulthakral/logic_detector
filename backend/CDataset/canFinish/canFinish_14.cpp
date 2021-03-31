class Solution {
private:
    //2->visited and processing; 1->visited and processed; 0->unvisited
    bool isCyclic(int v, vector<int>& vis, vector<vector<int>>& adj){
        vis[v] = 2;
        for(auto x : adj[v]) {
            if(vis[x] == 2)
                return true;
            else if(vis[x] == 0 && isCyclic(x, vis, adj))
                return true;
        }
        //if we reach here that means we've traversed all the vertices starting from vertex v and havent found a cycle so we mark the current vertex and visited and return false
        vis[v] = 1;
        return false;
    }
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        //make adjacency list
        vector<vector<int>> adj(n);
        for(auto x: pre) 
            adj[x[0]].push_back(x[1]);
        
        vector<int> visited(n, 0); //graph coloring
        for(int i = 0; i < n; ++i) { //takes care of disjoint graphs and tries all nodes to find possible cycles
            if(visited[i] == 0) { //dfs only of current node is not visited, if it is visited that means we've tried the possible cycles(if there might be any) form the current node and have marked it processed.
                if(isCyclic(i, visited, adj))
                    return false;
            }
        }
        return true;
    }
};
