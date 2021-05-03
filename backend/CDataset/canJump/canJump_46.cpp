class Solution {
public:
    bool canJump(vector<int>& nums) {
        int jump=nums[0]; // first jump
        for(int i=1;i<nums.size();i++){
            if(jump<=0) return false; 
            jump--;
            if(jump<=nums[i])
                jump=nums[i]; // update jump - greedy
        }
        if(jump>=0)
            return true;
        return false;
    }
};
