class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        vector<int> result(nums.end()-k,nums.end());
        result.insert(result.end(),nums.begin(),nums.end()-k);
        nums = result;
    }
};
