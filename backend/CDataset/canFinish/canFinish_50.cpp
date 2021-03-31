class Solution {//BEST1:  BFS: Time/Space: O(N), O(N), check Note1
public:// prerequisites: {child, parent}
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        vector<int> degrees(numCourses, 0);
        for(const auto& e: prerequisites){
            g[e[1]].emplace_back(e[0]);
            degrees[e[0]]++;
        }
        
        queue<int> q;
        for(int i = 0; i < numCourses; i++)
            if(degrees[i] == 0) q.push(i);  
        vector<int> ans;
        while(!q.empty()){
            auto cur = q.front(); q.pop(); ans.push_back(cur);
            for(const auto& next: g[cur])
                if(--degrees[next]==0) q.push(next);
        }
        return ans.size() < numCourses ? vector<int>() : ans;            
    }
};