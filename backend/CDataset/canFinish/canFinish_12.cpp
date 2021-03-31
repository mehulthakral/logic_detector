class Solution {
public:
    bool dfs(int node, vector<vector<int>>& g, vector<bool>& visited, vector<bool>& recStack)
    {
        visited[node] = true;
        recStack[node] = true; //Activate node
        
        for(int i=0; i<g[node].size(); i++)
        {
            int adj = g[node][i];
            
            if(recStack[adj] == true)  //node is activated
                return true;
            
            if(visited[adj] == false) //if child is unvisited
               if(dfs(adj, g, visited, recStack))
                return true;
        }
            
        
        //post-call -> all children have been visited
        recStack[node] = false; //node is deactivated
        return false;
    }
    
    bool canFinish(int n, vector<vector<int>>& pre) 
    {
        vector<vector<int>> graph(n);
        vector<int> res;
        vector<bool> visited(n, false);
        vector<bool> recStack(n, false);        
        
        for(int i=0; i<pre.size(); i++)
        {
            int dep = pre[i][0];
            int indep = pre[i][1];
            
            graph[indep].push_back(dep);
        }
        
        for(int i=0; i<n; i++) //for disconnected graph
        {
            if(visited[i] == false)
            {
                if(dfs(i, graph, visited, recStack)) //cycle exists
                    return false; //courses cannot be taken up
            }
        }        
        
        return true;
        
    }
};

