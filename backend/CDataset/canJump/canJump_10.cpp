class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1)
            return true;
        int maxi = nums[0];
        for(int i=1;i<nums.size()-1;i++){
            if(i>maxi)
                continue;
            
            maxi = max(maxi, i+nums[i]);
        }
        return (nums.size()-1)<=maxi;
    }
};
