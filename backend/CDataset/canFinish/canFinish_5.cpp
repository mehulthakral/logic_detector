class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses,vector<int>());
        vector<int> indegree(numCourses,0);

        for (int i = 0; i < prerequisites.size(); ++i) {
            ++indegree[prerequisites[i][0]];
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        queue<int> myque;
        for (int i = 0; i < indegree.size(); ++i)
            if (!indegree[i])
                myque.push(i);

        int counter = 0;
        while (!myque.empty()) {
            int cur = myque.front();
            myque.pop();
            ++counter;

            for (int i = 0; i < graph[cur].size(); ++i) 
                if (--indegree[graph[cur][i]] == 0)
                    myque.push(graph[cur][i]);
        }

        return numCourses == counter;
    }
};