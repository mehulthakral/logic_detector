class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> edgeCounts(numCourses, 0); // {node, incoming edges}
        queue<int> todo; // nodes that has no incoming edges, meaning starting points
        // Build the adjacency list
        for (vector<int> &p : prerequisites) {
            graph[p[1]].push_back(p[0]);
            // Count the incoming edges
            edgeCounts[p[0]]++;
        }
        // Find the nodes/roots that has no incoming edges
        for (int node = 0; node < edgeCounts.size(); node++) {
            // If a nodes has no incoming edge, this is a root
            if (edgeCounts[node] == 0) {
                todo.push(node);
            }
        }
        // If there is no any root node
        if (todo.empty()) {
            return false;
        }
        // Start BFS
        int processedCourseCount = 0; // Num of roots at the beginning
        while (!todo.empty()) {
            int cur = todo.front();
            todo.pop();
            // If we hit to 0 edge count, we don't need that node anymore
            if (edgeCounts[cur] == 0) {
                processedCourseCount++;
            } 
            for (int &neighbor : graph[cur]) {
                // Decrease our edge count
                edgeCounts[neighbor]--;
                if (edgeCounts[neighbor] == 0) {
                    todo.push(neighbor);
                }
            }
        }
        return (processedCourseCount == numCourses);
    }
};