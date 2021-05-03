class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        // store graph as an adjacency list
        vector<int> graph[numCourses];
        
        // use a vector to store the in-degree of each node
        vector<int> indegrees(numCourses, 0);  
        
        // use a priority queue to store all the nodes by acending order of their in-degree
        priority_queue<array<int,2>, vector<array<int,2>>, greater<array<int,2>>> nodesQueue;
        
        // graph construction
        for(int i=0; i<prerequisites.size(); i++) {
            int next = prerequisites[i][0];
            int prev = prerequisites[i][1];
            
            graph[prev].push_back(next);
            indegrees[next]++;
            
        }
        
        // add starting in-degrees to the node priority queue
        for(int i=0; i<numCourses; i++) {
            nodesQueue.push(array<int,2> {indegrees[i], i});
        }
        
        // get from the nodesQueue n times (all nodes will be retrieved by topological order)
        // if any node retrieved has in-degree > 0, a cycle must exist
        for(int i=0; i<numCourses; i++) {
            array<int,2> curNode = nodesQueue.top();
            nodesQueue.pop();
            if(curNode[0]>0) {
                return false;
            }
            
            //reduce the in-degree of all neighbours by -1 and put the updated in-degree to pq
            for(int next : graph[curNode[1]]) {
                indegrees[next]--;
                nodesQueue.push(array<int,2> {indegrees[next], next});
            }
        }
        
        return true;
            
    }
};