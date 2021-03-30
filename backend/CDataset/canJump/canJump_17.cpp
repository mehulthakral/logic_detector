class Solution {
public:
    bool canJump(vector<int>& nums) {
        for(int i = 0, max_jump = 0; i <= max_jump; ++i)
        {
            max_jump = max(max_jump, i+nums[i]);
            if(max_jump >= nums.size()-1) return true;
        }
        return false;   
    }
};