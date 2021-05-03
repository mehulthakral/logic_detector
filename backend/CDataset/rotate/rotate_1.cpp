class Solution {
public:
    #include<vector>
    void rotate(vector<int>& nums, int k) {
        reverse(nums.begin(),nums.end());                   // reverse the array
        reverse(nums.begin(),nums.begin()+k%nums.size());  // reverse the first k ele
        reverse(nums.begin()+k%nums.size(),nums.end());   // reverse the last n-k ele
    }
};
