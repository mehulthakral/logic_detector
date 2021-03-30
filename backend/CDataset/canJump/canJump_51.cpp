class Solution 
{
public:
    //AC - 16ms - forward searching the max index reachable;
    bool canJump(vector<int>& nums) 
    {
        int maxEnd = 0;
        for(int i = 0; i<nums.size() && i<=maxEnd; ++i) maxEnd = max(maxEnd, i+nums[i]);
        return maxEnd >= nums.size()-1;
    }

    //AC - 16ms - forward searching for the jump length;
    bool canJump(vector<int>& nums) 
    {
        for(int i = 0, des = 0; i < nums.size()-1; ++i, des--)
        {
            des = max(des, nums[i]);
            if(des<1 && i!=nums.size()-1) return false;
        }
        return true;
    }

    //AC - 16ms - backwards searching for the valid start index;
    bool canJump(vector<int>& nums) 
    {
        int validStart = nums.size()-1;
        for(int i = validStart-1; i >= 0; --i)
            if(i+nums[i] >= validStart) validStart = i;
        return validStart == 0;
    }

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