class Solution {
public:
    bool canFinish(int nc, vector<vector<int>>& arr) {
        vector<int>adj[nc+1];
        int inc[nc+1];
        memset(inc,0,sizeof(inc));
        for(int i=0;i<arr.size();i++) 
        {
            adj[arr[i][1]].push_back(arr[i][0]);
            inc[arr[i][0]]++;
        }
        queue<int>que;
        for(int i=0;i<nc;i++)
        {
            if(inc[i]==0)
                que.push(i);
        }
        while(!que.empty())
        {
            int tmp = que.front();
            que.pop();
            for(int i=0;i<adj[tmp].size();i++)
            {
                inc[adj[tmp][i]]--;
                if(inc[adj[tmp][i]]==0) que.push(adj[tmp][i]);
            }
        }
        for(int i=0;i<nc;i++)
        {
            if(inc[i]!=0) return false;
        }
        return true;
    }
};
