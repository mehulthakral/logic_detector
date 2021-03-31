class Solution {
public:
    bool canJump(vector<int>& nums) {
        int valid = 0; // Furthest it can reach currently.
        for (int i(0); i < nums.size() && i <= valid; ++i) {
			// maximum between the current furthest reached and the current value + index.
            valid  = max(valid, i + nums[i]); 
        }
        return valid >= nums.size() - 1; // if valid >= length - 1, then true else false.
    }
};
