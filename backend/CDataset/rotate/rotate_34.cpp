class Solution {
public:
    void rev(vector<int>& nums, int l, int r) {
        while(l <= r) {
            swap(nums[l], nums[r]);
            l++; r--;
        } 
    }
    
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        
        rev(nums, 0, n-k-1);
        rev(nums, n-k, n-1);
        rev(nums, 0, n-1);   
    }
};
