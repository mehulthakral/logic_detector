class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<bool> seen(numCourses, false), cycle(numCourses, false);
        // Build the adjacency list
        for (vector<int> &p : prerequisites) {
            graph[p[1]].push_back(p[0]);
        }
        // Start DFS for each Node
        stack<int> topoSort;
        bool hasCycle = false;
        for (int node = 0; node < graph.size(); node++) {
            if (seen[node] == false) {
                dfs(graph, node, seen, topoSort, hasCycle, cycle);
            }
        }
        int size = topoSort.size();
        return (numCourses == size && !hasCycle);
    }
    
    void dfs(vector<vector<int>> &graph, int cur, vector<bool> &seen, stack<int> &topoSort, bool &hasCycle, vector<bool> &cycle) {
        seen[cur] = true;
        cycle[cur] = true;
        for (int &child : graph[cur]) {
            if (seen[child] == false) {
                dfs(graph, child, seen, topoSort, hasCycle, cycle);
            }
            else if (cycle[child] == true) {
                hasCycle = true;
                return;
            }
        }
        cycle[cur] = false; // This is for cycle detection
        topoSort.push(cur);
    }
};