class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegrees(numCourses,0);
        
        queue<int>Q;
        
        for(auto e : prerequisites){
            adj[e[1]].push_back(e[0]);
            indegrees[e[0]]++;
        }
        
        for(int i=0; i < numCourses; i++ ){
            if(indegrees[i] == 0){
                Q.push(i);
            }
        }
        
        int count =0;
        
        while(!Q.empty()){
            
            int ele = Q.front();
            Q.pop();
            count++;
            
            for(auto e : adj[ele]){
                indegrees[e]--;
                if(indegrees[e] == 0){
                    Q.push(e);
                }
            }
        }
        return count == numCourses;
    }
};
