class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int l = nums.size(), s = 0;
        while (l-s > 1 && k) {
            k %= (l-s);
            for (int i=0; i<k; ++i) {
                nums[s+i] ^= nums[l-k+i];
                nums[l-k+i] ^= nums[s+i];
                nums[s+i] ^= nums[l-k+i];
            }
            s += k;
        }
    }
};
