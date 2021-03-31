bool canFinish(int numCourses, vector<vector>& prerequisites) {

    vector<vector<int>>adj(numCourses);
    vector<int>indeg(numCourses,0);
    for(int a=0:prerequisites)
    {
        adj[a[0]].push_back(a[1]); //Creating the adjency list for graph
        indeg[a[1]]++;// count indegree for each course
    }
    
    queue<int>q;
    for(int i=0;i<numCourses;i++)//ittrate through all the courses if indegree is zero then add it to queue 
        if(indeg[i]==0)
            q.push(i);

    while(!q.empty())
    {
        int curr=q.front();
        q.pop();
        for(int a:adj[curr])//ittrate throght the elsement of adj list of decresses the indegree of all the element of that list if indeg of any element is zero then add that to queue 
        {
            indeg[a]--;
            if(indeg[a]==0)
                q.push(a);
        }
        numCourses--;//decress the number of course by one
    }
    return numCourses==0;//return the answer
}
};