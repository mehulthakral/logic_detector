class Solution {//BEST2: BFS:Time/Space: O(N); O(N)
public:// prerequisites: {child, parent}
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        vector<int> degrees(numCourses, 0);
        for(const auto& e: prerequisites){
            g[e[1]].emplace_back(e[0]);
            degrees[e[0]]++; //Note1
        }
        
        queue<int> q;
        for(int i = 0; i < numCourses; i++)
            if(degrees[i] == 0) q.push(i);  // Note2
        int todoCnt=numCourses;
        while(!q.empty()){
            auto cur = q.front(); q.pop(); todoCnt--;
            for(const auto& next: g[cur])
                if(--degrees[next]==0) q.push(next); //Note3
        }
        return todoCnt == 0;
    }
};