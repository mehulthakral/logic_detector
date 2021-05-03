class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1) return true;
        if(nums[0]==0) return false;
        int step = nums[0];
        for(int i=1; i<nums.size()-1; i++){
            step = max(--step, nums[i]);
            if(step<=0) return false;
        }
        return true;
    }
};