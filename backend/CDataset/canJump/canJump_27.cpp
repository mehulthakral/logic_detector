/*
 *  The idea is to jump 1 index at a time while keeping the max jump value by 
 *  comparing current jump value vs max jump value. max jump value decreases by 1
 *  each time I jump 1 index.
 *  This way, if I have more zeroes than I can jump, my max jump value will
 *  become 0 before I reach the last index.
 */class Solution {
public:
bool canJump(vector<int>& nums) 
{
    if (nums.empty()) return false;
    
    int maxJumpVal = 0;
    int curIndex = -1;
    while (++curIndex + maxJumpVal < nums.size()) // if jump from where I am right now goes beyond the end, return true
    {
        int curJumpVal = nums.at(curIndex);
        maxJumpVal = max(curJumpVal, --maxJumpVal); // if my current jump value is bigger than the max jump value, update it. Otherwise, use max jump value where I am jumping from previous index.
        
        if (curJumpVal == 0) // if current jump value is 0, just continue with one less max jump value
        {
            if (maxJumpVal == 0 && curIndex < nums.size()-1) // if, however, max jump value is also zero and I am not on the last index, return false. If I am on the last index, curIndex will increment in the while loop condition and break out of the loop resulting in returning true
                return false;
            continue;
        }   
    }
    
    return true;
}
 };