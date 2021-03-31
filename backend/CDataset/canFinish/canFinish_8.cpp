class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> pre_req_count(numCourses,0);
        unordered_map<int,vector<int>> before_after;
        
        for (int i=0; i<prerequisites.size(); ++i) {
            // 
            before_after[prerequisites[i][1]].push_back(prerequisites[i][0]);
            //increase pre-req count of this course needed by 1 
            pre_req_count[prerequisites[i][0]]++;
        }
        
        int total = 0, curr;
        queue<int> q;
        //find all courses that don't have any prerequisites and add to queue
        for (int i=0; i<pre_req_count.size(); ++i) {
            if (pre_req_count[i] == 0)
                q.push(i);
        }
        
        while (!q.empty()) {
            curr = q.front(); q.pop();
            //find all courses that has this course as pre-req
            for (auto &i : before_after[curr]) {
                //this course now has one less pre-req
                pre_req_count[i]--;
                //if now this course is pre-req free, add to q
                if (pre_req_count[i] == 0)
                    q.push(i);
            } 
            ++total;
        }
        return total == numCourses;
    }
};
