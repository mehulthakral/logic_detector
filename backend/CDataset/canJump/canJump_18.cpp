class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n == 0 || n == 1) 
            return true;
        
        int i = 0;
        int maxStep = nums[0];//maxStemp represents the maximum jump length
        
        for (i = 1; i < n; ++i)
        {
            if (maxStep == 0)//can not jump to i-position
                return false;
            
            if (maxStep > (n-1-i))//can jump straight to the last index
                return true;
            
            --maxStep;//jump to i-position
            if (maxStep < nums[i])
                maxStep = nums[i];//update maxStep based on 'Greedy Strategy'
        }
    }
};