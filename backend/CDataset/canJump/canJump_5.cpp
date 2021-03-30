class Solution {
public:
    int canJump(vector<int>& nums) {
        int a=0;
        for(int i=0;i<nums.size();i++)
        {
            if(a>=i)
                a=max(a,i+nums[i]);
            else
                return false;
        }
        return true;
    }
};
