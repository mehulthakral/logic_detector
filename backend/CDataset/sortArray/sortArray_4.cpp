class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> countArr(100001, 0);
        // Count Each Element
        for (int num : nums) {
            countArr[50000 + num]++;
        }
        // Add previous counts 
        for (int i = 1; i < 100001; i++) {
            countArr[i] += countArr[i - 1];
        }
        // Create n places array
        vector<int> placesArr(nums.size(), 0);
        for (int &num : nums) {
            placesArr[countArr[50000 + num] - 1] = num;
            countArr[50000 + num]--;
        }
        return placesArr;
    }
};
