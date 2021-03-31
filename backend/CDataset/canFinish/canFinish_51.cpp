bool dfs(vector<vector<int>> &adjList, vector<int> &visited, int i) {
    // if visited[i] == 1, we have a cycle as it's part of 
    // current list being processed
    if(visited[i]) return visited[i] == 2;

    // marked processing
    visited[i] = 1;
    for(const auto &next: adjList[i])
        if(!dfs(adjList, visited, next)) return false;

    // marked visited
    visited[i] = 2;
    return true;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adjList(numCourses);
    for(const auto &i: prerequisites)
        adjList[i[0]].push_back(i[1]);

    vector<int> visited(numCourses, 0);
    for(int i = 0; i < numCourses; ++i)
        if(!visited[i]) 
            if(!dfs(adjList, visited, i)) return false;

    return true;;
}