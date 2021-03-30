bool canJump(vector<int>& nums) {
    if(nums.empty()) return true;
    int m = nums[0];
    for(auto i = 1; i < nums.size(); ++i)
    {
        if(m <= 0) return false;
        m = max(m - 1, nums[i]);
    }
    return true;
}