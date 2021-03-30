class Solution {
public:
    bool containsCycle(vector<vector<int>>& g, int i, vector<bool>& visited, vector<bool>& ongoing) {
        visited[i]= true;
        ongoing[i]= true;
        
        for(int j=0; j<g[i].size(); j++) {
            if(!visited[g[i][j]]) {
                if(containsCycle(g, g[i][j], visited, ongoing))
                    return true;
            }
            else if(visited[g[i][j]] && ongoing[g[i][j]])
                return true;
        }
        ongoing[i]= false;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n= prerequisites.size();
        vector<bool> visited(numCourses, false), ongoing(numCourses, false);
        vector<vector<int>>g(numCourses);
        
        for(int i=0; i<n; i++) 
            g[prerequisites[i][0]].push_back(prerequisites[i][1]);
               
        for(int i=0; i<numCourses; i++) {
            if(!visited[i]) {
                if(containsCycle(g, i, visited, ongoing)) return false;
            }
        }
        return true;
    }
};