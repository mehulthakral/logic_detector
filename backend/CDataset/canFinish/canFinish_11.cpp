class Solution {
public:
    bool CycleUtil(vector<int> Graph[], int start, vector<bool>& visited, vector<bool>& recSt){
        visited[start] = true;
        recSt[start] = true;
        
        for(int v : Graph[start]){
            if(! visited[v] && CycleUtil(Graph, v, visited, recSt)) 
                return true;
            else if(recSt[v]) return true;
        }
    recSt[start] = false;
    return false;
}
    
    bool canFinish(int n, vector<vector<int>>& preReq) {
        vector<int> Graph[n];
        
        //Make a Graph
        for(int i = 0; i < preReq.size(); i++){
            Graph[preReq[i][0]].push_back(preReq[i][1]);
        }
        
        //Check for cycle - if exist then taking all class not possible
        vector<bool> visited, all_ve;
        visited.assign(n, false);
        all_ve.assign(n, false);
        for(int i = 0; i < n; i++){
            if(! all_ve[i])
                if(CycleUtil(Graph, i,visited, all_ve)) return false; 
        }
        return true;
    }
};
