class Solution {
public:
    bool canJump(vector<int>& nums) {
       int jump = 0, size = nums.size(); 
       for(int i = 0 ; i < size-1;i++)
       {
           jump = nums[i] > jump ? nums[i] : jump;
           if(!jump) return false;
           jump--;
       } 
        return true;
    }
};
