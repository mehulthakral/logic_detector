class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {       
        vector<vector<int>> vv_graph(numCourses);   //Directed graph representing node relations specified by only prerequisites. 
                                                        //(u,v)->(u is prereq/parent and v is req/child).
        unordered_map<int, int> um_inFq;            //Map of nodes and their number of incoming edges
        unordered_set<int> us_noIn;                 //Set of nodes that have no incoming edges
        int count = 0;                              //Number of nodes added to topological ordering so far
        
        //Creates the graph. Initializes map.
        for (auto& pReq : prerequisites) {
            int chi = pReq[0], par = pReq[1];
            vv_graph[par].push_back(chi);
            um_inFq[chi] += 1;
            if (um_inFq.count(par) == 0) {
                um_inFq[par] = 0;
            } 
        }
        
        //Adds nodes to the set
        for (auto& node : um_inFq) {
            if (node.second == 0) {
                us_noIn.insert(node.first);
            }
        }
        
        //Take node with no incoming edges from set. Update incoming edge values of adjacent nodes by updating map.
        while (!us_noIn.empty()) {
            int curr = *(us_noIn.begin());
            us_noIn.erase(us_noIn.begin());
            for (auto& node : vv_graph[curr]) {
                if (--um_inFq[node] == 0) {
                    us_noIn.insert(node);
                }
            }
            count++;
        }
        
        return count == um_inFq.size();   //For true, # of Nodes in ordering must equal # of nodes depicted by prerequisites
    }
private:
    
};
