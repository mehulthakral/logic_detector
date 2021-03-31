class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size(),reachablesofar=0;
        
        for(int i=0;i<n;i++){
            if(reachablesofar<i) return false;
            reachablesofar=max(reachablesofar, i+nums[i]);
            if(reachablesofar>=n-1) return true;
        }
    }
};