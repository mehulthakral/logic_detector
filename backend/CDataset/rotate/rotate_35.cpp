class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        while(k > nums.size()) k -= nums.size();
        nums.insert(nums.begin(), nums.end() - k, nums.end());
        nums.erase(nums.end() - k, nums.end());
    }
};
