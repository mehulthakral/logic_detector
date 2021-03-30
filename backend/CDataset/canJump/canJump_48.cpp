class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        int k = nums[0];
        for(int i = 0; i <= k; ++i) {
            if((i+nums[i]) >= (size-1)) return true;
            else k = max(k, i+nums[i]);
        }
        return false;
    }
};
