class Solution {
public: 
    
    vector<vector<int>> createList(vector<vector<int>> &prerequisites, int numCourses) { 
        
        vector<vector<int>> adjList(numCourses); 
        
        for(int i = 0; i < prerequisites.size(); i++) { 
            
            adjList[prerequisites[i][0]].push_back(prerequisites[i][1]); 
            
        } 
        
        return adjList;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {  
        
        int count = 0;
        
        vector<vector<int>> adjList = createList(prerequisites, numCourses); 
        
        unordered_map<int, int> indegree;
        unordered_map<int, bool> visited; 
        
        for(int i = 0; i < numCourses; i++) { 
            indegree[i] = 0;
        } 
        
        for(int i = 0; i < prerequisites.size(); i++) {  
            indegree[prerequisites[i][1]]++;
        } 
        
        queue<int> q; 

        for(auto i : indegree) { 
            
            if(i.second == 0) { 
                q.push(i.first); 
                visited[i.first] = true;  
                count++;
            }
        }
        
        if(q.empty()) { 
            return false;
        } 
        
        else { 
            
            while(!q.empty()) { 
            
                for(int i : adjList[q.front()]) { 
                
                    indegree[i]--; 
                
                    if(!visited[i] && indegree[i] == 0) { 
                        q.push(i); 
                        visited[i] = true; 
                        count++;
                    } 
                }  
                q.pop();
            } 
        } 
        
        return count == numCourses;
    }
};
