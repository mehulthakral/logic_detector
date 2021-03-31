class Solution {
public:
    bool canJump(vector<int>& nums) { 
     int maxindex = 0;
     for(int i=0;i<nums.size()-1;i++){
       if(nums[i]){
         if(nums[i]+i > maxindex) maxindex = nums[i]+i;
       }else if(maxindex <= i) return false;
     } 
     return true;   
    }
};
