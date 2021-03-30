class Solution {
public:
    bool cycle = false;
    map<int,vector<int>>m;
    map<int,bool>vis;
    void dfs(int root)
    {
        if(cycle)
            return;
        vis[root] =true;
        for(auto i:m[root] )
        {
            if(m[i].size()!=0&&vis[i])
            {
               cycle = true;
               return;
            }
             dfs(i); 
             m[root].pop_back();
        }
    }
    bool dfsUtil(int n)
    {
        if(n==0)
            return true;
        for(int i=0;i<n;i++)
        {
            if(!vis[i]&&!cycle)
                dfs(i);
        }
        return cycle;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i=0;i<prerequisites.size();i++)
        {
            m[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        return !dfsUtil(numCourses);
    }
};
