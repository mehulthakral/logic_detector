class Solution {
public:
    bool canJump(vector<int>& nums) {
        int dif, j;
        
        for(j = nums.size() - 1, dif = 0; j >= 0; j--, dif++){
            if(nums[j] >= dif){
                dif = 0;
            }
        }
        return (i == dif);
    }
};