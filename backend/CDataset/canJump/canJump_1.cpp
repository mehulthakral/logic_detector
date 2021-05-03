class Solution {
public:
    bool canJump(vector<int>& nums) {
        int index=nums.size()-1;
        for(int i=nums.size()-2;i>=0;--i){
            if(i+nums[i]>=index){
                index=i;
            }
        }
        return index==0;
    }
};
