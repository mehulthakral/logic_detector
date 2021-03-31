class Solution {
    public:
        bool canJump(vector<int>& nums) {
            int n=nums.size();// get first constraint
            
            if(n==0)// corner case
            return false;
            int maxIndex=0;
            for(int i=0;i<n&&i<=maxIndex;i++)// two constraints. It will stop when either one terminates
                maxIndex=max(maxIndex,i+nums[i]);// update dynamic range every time
                
                if(maxIndex>=n-1)// cover last index
                return true;
                else// not cover
                return false;
            
            
        }
    };