class Solution {
public:
    set <int> vis;
    set <int> ordering;
    
    bool dfs(vector < vector<int> > &graph, int x) {
        vis.insert(x);
        ordering.insert(x);
        
        for(int i=0;i<graph[x].size();i++) {
          int v = graph[x][i];
            
          if(vis.find(v) != vis.end()) {
              if(ordering.find(v) != ordering.end()) {
                  return false;
              }
          }
            
          if(!dfs(graph, v)) return false;
        }
		
        ordering.erase(x);
        return true;
    }
        
    bool canFinish(int numCourses, vector<vector<int>>& pq) {
       vector < vector<int> > graph(numCourses);
        
       for(int i=0;i<pq.size();i++) {
           int u = pq[i][0], v = pq[i][1];
           
           graph[u].push_back(v);
       }
        
       for(int i=0;i<numCourses;i++) {
           if(vis.find(i) == vis.end()) {
               if(!dfs(graph, i)) return false;
           }
       }
       return true;
       
    }
};
