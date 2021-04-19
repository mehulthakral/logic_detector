class Solution {
public:
bool canJump(vector<int>& nums) {
    int len = nums.size() - 1; // ignore last step

    // If there is none 0, then it is OK.
    // If there is a 0, it should be like this:
    // 7,[?],5,4,3,2,1,0, ... the [?] should be greater than 6
    for (int i=0; i<len; ++i) {
        if (0 == nums[i]) {
            bool breakZero = false;
            for (int j=i-1, count=1; j>=0; --j, ++count) {
                if (nums[j] > count) {
                    breakZero = true;
                    break;
                }
            }
            if (false == breakZero) {
                return false;
            }
        }
    }
    
    return true;
}
};