class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(auto& p : prerequisites) graph[p.front()].push_back(p.back());

        vector<bool> done(numCourses);
        vector<bool> visited(numCourses);

        for(int i = 0; i < graph.size(); ++i)
            if(! check(i, graph, visited, done)) return false;
        return true;
    }
    
protected:
    bool check(int course, vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& done)
    {
        if(done[course]) return true;
        if(visited[course]) return false;

        visited[course] = true;
        for(int n : graph[course])
            if(!check(n, graph, visited, done)) return false;
        visited[course] = false;

        done[course] = true;
        return true;
    }
};
