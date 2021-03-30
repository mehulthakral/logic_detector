class Solution {
public:
    bool cycle(vector<vector<int>> & pre, vector<int> & visited,int pos)
    {
       if(visited[pos] == 1) return true; 
       if(visited[pos] == 2) return false; 
       visited[pos] = 1; 
       for(int x: pre[pos])
          if(cycle(pre,visited,x)) return true; 
       visited[pos] = 2;
       return false; 
    }
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
      vector<vector<int>> adjList(numCourses);  
      vector<int> visited(numCourses,0); 
        for(auto v : pre)
            adjList[v[1]].push_back(v[0]); 
        for(int i = 0 ; i < numCourses;i++)
            if(cycle(adjList,visited,i)) return false; 
        return true;
    }
};