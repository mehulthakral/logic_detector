class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int max_position=0;
        for(int i=0;i<n;i++){
            max_position=max(max_position,nums[i]+i);
            if(max_position>=n-1)
                return true;
            if(max_position==i)
                return false;
        }
        return false;
    }
};
