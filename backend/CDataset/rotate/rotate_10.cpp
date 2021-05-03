class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        reverse(nums.end()-k,nums.end()); //reverse nums[n-k] to nums[n-1]
        reverse(nums.begin(),nums.end()-k); //reverse nums[0] to nums[n-k-1]
        reverse(nums.begin(),nums.end());  //reverse complete array
    }
};
