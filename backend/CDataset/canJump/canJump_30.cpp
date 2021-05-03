class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1)
            return true;
        
        int max_so_far = 0;
        
        for(int i = 0; i < n-1; i++){
            
            if(nums[i] == 0 and i == max_so_far)
                return false;
            
            if(i + nums[i] >= n-1)
                return true;
            max_so_far = max(max_so_far, i + nums[i]);
        }
        return false;
    }
};
