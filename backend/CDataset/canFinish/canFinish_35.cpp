class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prereq) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses);
        
        for(int i=0;i<prereq.size();i++){
            graph[prereq[i][0]].push_back(prereq[i][1]);
            indegree[prereq[i][1]]++;
        }
        stack<int> zeroDegreeNodes;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                //cout<<i<<" ";
                zeroDegreeNodes.push(i);
            }
        }
        int count=0;
        while(!zeroDegreeNodes.empty()){
            int curr=zeroDegreeNodes.top();
            //cout<<curr<<" ";
            zeroDegreeNodes.pop();
            count++;
            for(int i=0;i<graph[curr].size();i++){
                if(--indegree[graph[curr][i]]==0){
                    zeroDegreeNodes.push(graph[curr][i]);
                }
            }
        }
        return count==numCourses;
        
    }
};