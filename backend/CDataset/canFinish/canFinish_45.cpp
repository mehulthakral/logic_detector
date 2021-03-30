class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int> > graph;
        unordered_map<int, int> indegree;
        int child, parent, i;
        queue<int> source;
        vector<int> result, children;
        
        // init graph
        for(i=0; i<numCourses; i++) {
            indegree[i] = 0;
            graph[i] = vector<int>();
        }
        
        // populate graph
        for(auto req: prerequisites) {
            parent = req[1];
            child = req[0];
            indegree[child]++;
            graph[parent].push_back(child);
        }
        
        // populate source
        for(auto entry: indegree) {
            if(entry.second == 0) {
                source.push(entry.first);
            }
        }
        
        // bfs
        while(source.size()) {
            parent = source.front();
            source.pop();
            result.push_back(parent);
            children = graph[parent];
            for(auto child: children) {
                indegree[child]--;
                if(indegree[child] == 0) {
                    source.push(child);
                }
            }
        }
        return result.size()==numCourses;
    }
};