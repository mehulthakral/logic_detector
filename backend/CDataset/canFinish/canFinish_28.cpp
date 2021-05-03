class Solution {
public:
    bool cycle(vector<vector<int>> &graph, vector<bool> &visited, vector<bool> &rec_stack, int s){
        visited[s] = true;
        rec_stack[s] = true;
        for(int i = 0; i < graph[s].size(); i++){
            int u = graph[s][i];
            if(!visited[u] && cycle(graph, visited, rec_stack, u)){
                return true;
            }else if(rec_stack[u]){
                return true;
            }
        }
        rec_stack[s] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int i, j;
        vector<vector<int>> graph(numCourses, vector<int>());
        for(i = 0; i < prerequisites.size(); i++){
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        vector<bool> visited(numCourses, false), rec_stack(numCourses, false);
        
        for(i = 0; i < numCourses; i++){
            if(!visited[i]){
                if(cycle(graph, visited, rec_stack, i)){
                    return false;
                }
            }
        }
        return true;
    }
};
