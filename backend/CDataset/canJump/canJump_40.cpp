class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size(), max_so_far=0;;
        if(n==0) return true;
        
        for(int i=0; i<= max_so_far && max_so_far<n; i++){
            max_so_far= max(max_so_far, i + nums[i]);
        }
        if(max_so_far>=n-1)
                return true;
        else
            return false;
        
    }
};