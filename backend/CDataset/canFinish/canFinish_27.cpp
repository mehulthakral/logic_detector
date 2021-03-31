class Solution {
public:
    bool dfs(int z, vector<vector<int>>& courses, vector<int>& vis) {
        vis[z] = 1;
        for(auto it: courses[z]) {
            if(vis[it] == 1 || (vis[it] == 0 && !dfs(it, courses, vis))) {
                return false;
            }
        }
        vis[z] = 0;
        return true;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        if(n == 0) {
            return true;
        }
        vector<vector<int>> courses(numCourses);
        for(auto i: prerequisites) {
            courses[i[1]].push_back(i[0]);
        }
        vector<int> vis(numCourses, 0);
        for(int i=0;i<numCourses;i++) {
            if(!dfs(i, courses, vis)) {
                return false;
            }
        }
        return true;
    }
};