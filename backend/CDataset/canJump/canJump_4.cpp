class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        if(nums.size()==1)
            return 1;
        else if(nums[0]==0)
            return 0;
        
        int count=0;
        
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]==0)
            {
                count=0;
                for(int j=i-1;j>=0;j--)
                {
                   if(nums[j]+j>=i+1)
                   {
                      i=nums[j]+j-1;
                      ++count;
                      break;
                   }
                }
                if(count==0)
                    return 0;
            }
            else
                i=i+nums[i]-1;
        }
        
        
        return 1;
    }
};
