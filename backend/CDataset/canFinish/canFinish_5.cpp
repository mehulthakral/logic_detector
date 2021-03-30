bool dfs(int index,int visited[],vector<int> adj[]){
        if(visited[index]==1)               //1- visited comes there is cycle
            return true;                    
        visited[index]=1;
        for(int i=0;i<adj[index].size();i++){
            if(visited[adj[index][i]]!=2){  //2 - checked dfs only if not already checked
                if(dfs(adj[index][i],visited,adj))
                    return true;
            }
        }
        visited[index]=2;                   //after visited i.e; no cycle make checked
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& adj) {
        int visited[n];
        for(int i=0;i<n;i++){
            visited[i]=0;
        }
        vector<int> arr[n];             //vector of vectors to adjacency list
        for(int i=0;i<adj.size();i++){
            arr[adj[i][0]].push_back(adj[i][1]);
        }
        for(int i=0;i<n;i++){
            if(visited[i]==0){              //0 --- unvisited
                if(dfs(i,visited,arr))      //1 --- visited
                    return false;           //2 --- checked
            }
        }
        return true;
    }
