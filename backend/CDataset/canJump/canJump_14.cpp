class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        
        int maxreach=0;
        for(int i=0; i<n; i++){
            if(maxreach<i)
                return false;
            maxreach=max(maxreach, i + nums[i]);
        }
        return true;
    }
};