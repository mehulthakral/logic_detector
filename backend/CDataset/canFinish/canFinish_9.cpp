class Solution {
public:
    bool dfs(vector<int>adj[],vector<int>&visited,vector<int>&rec,int node)
{
    visited[node]=1;
    rec[node]=1;
    for(auto it:adj[node])
    {
        if(rec[it]){
            return true;
        }
        else if(!visited[it] && dfs(adj,visited,rec,it))
        {
            return true;
        }
    }
    rec[node]=0;
    return false;
}
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        
        // contruct a graph (adjacency list from Prerequisites)
        vector<int>adj[numCourses];
        for(auto it:pre)
        {
            adj[it[0]].push_back(it[1]);
        }
         int V=numCourses;
        // for(int i=0;i<V;i++)
        // {
        //     cout<<i<<"-->";
        //     for(auto it:adj[i])
        //     {
        //         cout<<it<<" ";
        //     }
        //     cout<<endl;
        // }
       
        vector<int>visited(V,0);
        vector<int>rec(V,0);
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                if(dfs(adj,visited,rec,i))
                {
                    return false;
                }
            }
        }
        return true;
        
        
    }
};
