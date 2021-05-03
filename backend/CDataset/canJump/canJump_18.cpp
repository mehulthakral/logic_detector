class Solution 
{
public:
    //AC - 16ms - backwards searching for zero jump length and then make sure it can be jumped over;
    bool canJump(vector<int>& nums) 
    {
        int d = 0;
        for(int i = nums.size()-2; i >= 0; --i)
        {
            if(nums[i] == 0)
            {
                int d = 1;
                while(d > nums[i])
                {
                    d++;
                    i--;
                    if(i < 0) return false;
                }
            }
        }
        return true;
    }
};