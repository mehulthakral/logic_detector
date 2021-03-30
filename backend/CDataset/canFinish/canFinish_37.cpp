class Solution {
public:
    vector<int>res;
    vector<int>in;
    void check(int numCourses,vector<vector<int>>& v)
    {   queue<int>q;
        for(int i=0;i<numCourses;i++)
           if(in[i]==0)
              q.push(i);   
        while(q.size()>0)
        {   int cur=q.front();
            res.push_back(cur);
            q.pop();
            for(int node:v[cur])
            {
                in[node]--;
                if(in[node]==0)
                    q.push(node);
            }
        }
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>v(numCourses);
        in.resize(numCourses);
        for(int i=0;i<prerequisites.size();i++)
        {
            v[prerequisites[i][0]].push_back(prerequisites[i][1]);
            in[prerequisites[i][1]]++;
        }
        check(numCourses,v);
        if(res.size()==numCourses) return true;
        else return false;
    }
};