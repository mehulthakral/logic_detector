class Solution {
public:
    bool canJump(vector<int>& nums) {
        for(int i = 0, max_jump = 0; i < nums.size() && max_jump < nums.size()-1; ++i)
        {
            if(i > max_jump) return false;
            max_jump = max(max_jump, i+nums[i]);
        }
        return true;
    }
};