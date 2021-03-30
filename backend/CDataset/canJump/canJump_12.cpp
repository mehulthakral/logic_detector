class Solution {
public:
    bool canJump(vector<int>& nums) {
        // support variables
        int iLen = nums.size();
        bool canReach[iLen];
        for (bool &b: canReach) b = false;
        canReach[0] = {1};
        for (int i = 0, jLen, lastChecked = 0, jumps; i < iLen - 1; i++) {
            // exiting when unreachable/unreached blocks are met
            if (!canReach[i]) break;
            // updating canReach with the latest jump
            jumps = nums[i];
            jLen = min(iLen, i + jumps + 1);
            for (int j = max(lastChecked, i) + 1; j < jLen; j++) canReach[j] = true;
            // updating lastChecked
            lastChecked = jLen - 1;
        }
        return canReach[iLen - 1];
    }
};