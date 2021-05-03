class Solution {
public:
    bool canJump(vector<int>& nums) {
        int closest_stand=nums.size()-1;
        for (int i=closest_stand;i>=0;--i) {
            if (i+nums[i]>=closest_stand) closest_stand=i;
        }
        return closest_stand==0;
    }
};