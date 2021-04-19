class Solution {
public:
    bool canJump(vector<int>& nums) {
        // support variables
        int last = 0, len = nums.size() - 1;
        for (int i = 0; i < len; i++) {
            // exit condition - unreachable cell met
			if (i > last) break;
			// updating last
            last = max(last, nums[i] + i);
        }
        return last >= len;
    }
};