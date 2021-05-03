class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int m = k%nums.size();
        
        reverse(nums.begin(), nums.end());
        
        reverse(nums.begin()+m, nums.end());
        
        reverse(nums.begin(), nums.begin()+m);
    }
};
