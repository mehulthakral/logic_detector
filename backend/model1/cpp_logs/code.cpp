
#include <bits/stdc++.h>
#include <chrono>
using namespace std;
class Solution {
public:
    #include<vector>
    vector<bool> vist; //int d=0;
    bool dfs(int p,vector<bool> &vis,vector<int> adj[]){
        //d++; cout<<d<<endl;
        if(vis[p]) return false;
        if(vist[p]) return true;
        vis[p]=true; vist[p]=true;
        for(int g:adj[p]){
            if(!dfs(g,vis,adj)) return false;
        }
        vis[p]=false;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses]; vector<bool> vis(numCourses,false), _vis(numCourses,false);
        vist=_vis;
        for(auto g:prerequisites) adj[g[1]].push_back(g[0]);
        for(int i=0;i<numCourses;i++){
            if(vist[i]) continue;
            if(!dfs(i,vis,adj)) return false;
        }
        return true;
    }
};

int main()
{
    auto start = chrono::high_resolution_clock::now();
  
    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);

    Solution MyObj;
int inp1=2;
vector<vector<int>> inp2 {{1,1},{1,0}};
MyObj.canFinish(inp1,inp2);    
    auto end = chrono::high_resolution_clock::now();
  
    // Calculating total time taken by the program.
    double time_taken = 
      chrono::duration_cast<chrono::nanoseconds>(end - start).count();
  
    time_taken *= 1e-9;
  
    cout << fixed 
         << time_taken << setprecision(9);
    return 0;
}
    