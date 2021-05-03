class Solution {
public:
    bool canJump(vector<int>& nums) {
        int last=0;
        for(int i=0;i<nums.size();i++)
        {
            if(i>last) return false;            
            last=max(last,i+nums[i]);
        }
        return true;
    }
};
