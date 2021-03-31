class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.empty()) return true;
        if(nums[0]==0)
        {
            if(nums.size()==1) return true;
            else return false;
        }
        vector<int> zero;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]==0)
            {
                zero.push_back(i);
            }
        }
        bool flag;
        for(int i=0;i<zero.size();i++)
        {
            flag=false;
            for(int j=0;j<zero[i];j++)
            {
                if(nums[j]+j>zero[i]) 
                {
                    flag=true;
                    break;
                }
            }
            if(!flag) return false;
        }
        return true;
    }
};