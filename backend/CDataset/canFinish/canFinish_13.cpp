class Solution {
public:
    bool dfs(vector<int> nums[],vector<bool> &passedThrough,vector<bool> visited,int node)
    {
        if(visited[node] == true)
        return false;
        
        visited[node] = true;

        for(int i=0;i<nums[node].size();i++)
        {
            if(passedThrough[nums[node][i]] == false)
            {
                if(dfs(nums,passedThrough,visited,nums[node][i])==false)
                return false;
            }
        }
        passedThrough[node] = true;
        return true;
    }
    
    bool canFinish(int courses, vector<vector<int>>& pre) {
        
        vector<bool> passedThrough(courses,false);
        vector<bool> visited(courses,false);
        
        int n= pre.size();
        vector<int> nums[courses];
        
        for( int i=0;i<n;i++)
        nums[pre[i][0]].push_back(pre[i][1]);

        for(int i=0;i<courses;i++)
        {
            if(passedThrough[i] == false)
            {
                if(dfs(nums,passedThrough,visited,i ) == false)
                return false;
            }
        }
        return true;
    }
};
