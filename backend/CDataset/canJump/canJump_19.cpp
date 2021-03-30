class Solution {

public:
bool canJump(vector& nums)
{
int size= nums.size(), end_idx=0;

    if(size<=1)
        return true;
    
    end_idx= nums[0];
    for(int i=1;i<size;i++)
    {
        if(i>end_idx)
            return false;
        
        if((nums[i]+i) > end_idx)
            end_idx = nums[i]+ i;
        
        if(end_idx>=size-1)
            return true;
    }
}
};