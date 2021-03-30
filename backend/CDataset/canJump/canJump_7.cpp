class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach = nums.size() - 1;
        for(int i = nums.size() - 2; i >= 0; i--){
            if(i + nums[i] >= reach) reach = i;
        }
        if(!reach) return true;
        return false;
    }
};
