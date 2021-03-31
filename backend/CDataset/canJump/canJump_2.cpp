class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reachable = nums.size()-1;
        for(int i=nums.size()-2;i>=0;--i)
            if(i+nums[i] >= reachable) reachable = i;
        return reachable == 0;
    }
};
