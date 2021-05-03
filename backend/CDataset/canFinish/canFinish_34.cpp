class Solution {
private:
    int not_processed=0;
    int processing=1;
    int processed=2;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prereq) {
        vector<int> visited(numCourses,0);
        
        vector<vector<int>> graph(numCourses);
        
        for(int i=0;i<prereq.size();i++){
            graph[prereq[i][0]].push_back(prereq[i][1]);
        }
        for(int i=0;i<numCourses;i++){
            if(visited[i]==not_processed){
                if(!dfs(i,graph,visited)){  //return false if cycle exist
                    return false;  
                }
            }
        }
        return true;
    }
    bool dfs(int node,vector<vector<int>>& graph,vector<int>& visited){
        if(visited[node]==processing){
            return false;
        }
        if(visited[node]==processed){
            return true;
        }
        visited[node]=processing;
        for(int i=0;i<graph[node].size();i++){
            if(!dfs(graph[node][i],graph,visited)){
                return false;
            } 
        }
        visited[node]=processed;
        return true;  //means the graph is acyclic
    }
};