class Solution
{
public:
    bool has_cycle(vector<int>adj[],vector<bool>&vis,vector<bool>&stk,int src)
    {
        if(!vis[src])
        {
            vis[src]=true;
            stk[src]=true;
            for(auto it:adj[src])
            {
                if(stk[it])
                {
                    return true;
                }
                else if(!vis[it] && has_cycle(adj,vis,stk,it))
                {
                    return true;
                } 
            }
            stk[src]=false;
        }
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<int>adj[numCourses];
        for(auto it:prerequisites)
        {
            adj[it[0]].push_back(it[1]);
        }
        vector<bool>vis(numCourses,false),stk(numCourses,false);
        for(int i=0;i<numCourses;i++)
        {
            if(!vis[i])
            {
                if(has_cycle(adj,vis,stk,i))
                {
                    return false;
                }
            }
        }
        return true;
    }
};
