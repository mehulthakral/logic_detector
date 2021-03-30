bool canJump(vector<int>& nums) {
    unsigned int maxReach = 0;
    for (unsigned int i = 0; i < nums.size(); i++) {
        if (maxReach < i)  // cannot reach i 
            return false;
        if (maxReach >= nums.size()-1)
            return true;  //early return 
        maxReach = max(maxReach, i+nums[i]);
    }
    return true;
}