// DFS for detecting cycle
// TC: O(V + E), since entire edge loop runs for each vertex
// The idea is to detect if there is a back edge from a node to
// one of nodes in the current branch, so we make the current node as visited
// and do DFS to go down the branch, if there is a back edge leading to a node 
// in the current branch then a cycle is detected
bool dfsCycle(int curr, vector<bool>& visited, vector<bool>& rec_stack,
                  vector<vector<int>>& g) {
	// mark the current as visited
	visited[curr] = true;
	// add to recursion stack
	rec_stack[curr] = true;
	for(int i = 0; i < g[curr].size(); i++) {
		// if the neighbour is already visited, cycle is there
		if(rec_stack[g[curr][i]])
			return true;
		if(dfsCycle(g[curr][i], visited, rec_stack, g))
			return true;
	}

	// make the current node as unvisited, because at a time we need
	// to keep track of nodes in the same branch only
	rec_stack[curr] = false;
	return false;
}

// DFS driver
// TC: O(V + E)
bool DFS(int numCourses, vector<vector<int>>& g) {
	// to keep track of visited courses
	vector<bool> visited(numCourses, false);
	// for keeping track of recursion stack in DFS branch
	vector<bool> rec_stack(numCourses, false);
	// check if a cycle is there or not, we start DFS from each
	// vertex in case the graph is disconnected
	for(int i = 0; i < numCourses; i++) 
		if(!visited[i] && dfsCycle(i, visited, rec_stack, g))
			return false;
	return true;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
	// make edges for each vertex
	vector<vector<int>> g(numCourses);
	for(auto& edge: prerequisites) 
		g[edge[0]].emplace_back(edge[1]);

	// using DFS
	//return DFS(numCourses, g);

	// using BFS
	return !BFS(numCourses, g);
}