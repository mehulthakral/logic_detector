class Solution {
public:
    bool canJump(vector<int>& nums) {
        int minSteps=1;      //no of steps required from any index to reach last index
        for(int i=nums.size()-2;i>=0;i--)
            nums[i]<minSteps?minSteps++:minSteps=1;   //if we can reach to last index from here, minSteps from i-1th index is 1
        return minSteps>1?false:true;    //if minSteps>1, we were not able to reach last index from first
    }
};
