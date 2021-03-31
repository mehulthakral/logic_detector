class Solution {
public:
    bool canJump(vector<int>& arr) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int n = arr.size();
        int maxReach = 0;
        
        for(int i=0; i<n; i++){
            if(maxReach < i)
                return false;
            maxReach = max(maxReach, arr[i]+i);
        }
        return true;
    }
};
