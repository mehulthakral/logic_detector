class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        int baseIndex = 0;
        while (k)
        {
            for (int j = 0; j < k; j++)
                swap(nums[baseIndex + j], nums[nums.size() - k + j]);
            baseIndex += k;            
            k %= nums.size() - baseIndex;
        }
    }
};
