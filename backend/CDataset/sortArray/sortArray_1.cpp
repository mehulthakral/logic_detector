class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int counts[100001] = {0};
        // Maps negatives starting from 0
        for (int &num : nums) {
            counts[num + 50000]++;
        }
        vector<int> result(nums.size(), 0);
        for (int i = 0, j = 0; i < 100001; i++) {
            while (counts[i] > 0) {
                result[j] = i - 50000;
                j++;
                counts[i]--;
            }
        }
        return result;
    }
};
