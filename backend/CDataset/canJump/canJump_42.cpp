class Solution {
    
public:
    bool canJump(const vector<int>& nums) {
        if (nums.size() == 1) return true; // Handle edge case of a vector being given of size 1
        for (int i{nums[0]}; i > 0; --i) {
            bool res = nums.begin() + i >= nums.end() - 1 ? true : canJump({nums.begin() + i, nums.end()});
            if (res) return true;
        }
        return false;
    }
};
