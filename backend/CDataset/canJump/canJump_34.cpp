class Solution {
public:
    bool canJump(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int n = nums.size();
        int maxReach = 0;
        
        for(int i=0; i<n; i++){
            if(maxReach < i)
                return false;
            maxReach = max(maxReach, nums[i]+i);
        }
        return true;
    }
};
