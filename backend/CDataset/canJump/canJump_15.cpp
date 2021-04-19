//Jump Game
//O(1) space solution
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 0) return false;
        if (nums.size() == 1) return true;
        
        int n = nums.size();
        int jump = 0;
        for (int i = 1; i < n; i++) {
            jump = max(nums[i-1], jump) - 1;
            if (jump < 0) return false;
        }
        return true;
    }
};