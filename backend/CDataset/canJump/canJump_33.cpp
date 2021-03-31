typedef long long ll;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        ll store = nums.size()-1;
        ll r = nums.size()-2;
        ll l = 0;
        while(l<=r)
        {
            if(nums[r]>=(store-r))
            {
                store = r;
                r--;
            }
            else
                r--;
        }
        if(store==0)
            return true;
        else
            return false;
        
    }
};
