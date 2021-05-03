class Solution {
public:

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int> > children(numCourses);
        vector<int> dependancy (numCourses, 0);
        for(int i=0; i<prerequisites.size(); i++){
            children[prerequisites[i][1]].push_back(prerequisites[i][0]);
            dependancy[prerequisites[i][0]] ++;
        }
                  
        
        vector<int> visited (numCourses, 0);
        queue<int> to_process;
        
        for(int i=0; i<numCourses; i++){
            if(dependancy[i]==0){
                to_process.push(i);
                visited[i] = 1;
            }
        }
        
        
        
        while(to_process.size()>0){
            while(to_process.size()>0){
                int c = to_process.front();
                for(int child: children[c]){
                    dependancy[child] --;
                }
                visited[c] = 1;
                to_process.pop();
            }
            
            for(int i=0; i<numCourses; i++){
                if(dependancy[i]==0 && visited[i]==0){
                    to_process.push(i);
                    visited[i] = 1;
                }
            }
            
        }
        
        for(int i=0; i<numCourses; i++){
            if(visited[i]==0) return false;
        }
        
        return true;
    }
};
