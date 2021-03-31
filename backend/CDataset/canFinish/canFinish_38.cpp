class Solution {
public:
    bool isValid = false;
     vector<int>vis;
    bool dfs(int node,vector<vector<int>>& graph)
    {
        if(vis[node]==2)
            return true;
        vis[node]=2;
        for(int i=0;i<graph[node].size();i++)
        {
            if(vis[graph[node][i]]!=1)
            {
                if(dfs(graph[node][i],graph))
                    return true;
            }
        }
        vis[node]=1;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>graph(numCourses);
        if(prerequisites.size()==0)
            return true;
        for(int i=0;i<prerequisites.size();i++)
        {
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for(int i=0;i<numCourses;i++)
        {
           // cout<<"rishu"<<endl;
            for(int j=0;j<graph[i].size();j++)
            {
                cout<<graph[i][j]<<" ";
            }
            cout<<endl;
        }
         vis.resize(graph.size(),0);
        for(int i = 0; i < numCourses; i++)
        {
            if(vis[i] == 0)
            {
                if(dfs(i,graph))
                    return false;
            }
        }
         return true;
    }
};