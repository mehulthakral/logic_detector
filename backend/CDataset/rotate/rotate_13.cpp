class Solution {
public:
    void rotate(vector<int>& nums, int k, int s=0) {
        int l = nums.size(), tmp;
        if (l-s <= 1) return;
        k %= (l-s);
        for (int i=0; i<k; ++i) {
            tmp = nums[s+i];
            nums[s+i] = nums[l-k+i];
            nums[l-k+i] = tmp;
        }
        if (k) rotate(nums, k, s+k);
    }
};
