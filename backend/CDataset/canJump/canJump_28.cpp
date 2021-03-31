class Solution {
public:
    bool canJump(vector<int>& nums) {
        int u = 1;
        for (int i = 0; i < nums.size(); i ++){
            if (--u < 0) return false;
            u = max(nums[i], u);
        }
        return true;
    }
};