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
        
        int idx = 0, flag = 0;
        
		// by symmetry
        if(k > n/2) {
            rev(nums, 0, n-1);
            k = n-k;
            flag = 1;
        }
        
        for(int i=n-k;i<n;i++) {
            swap(nums[i], nums[idx]);
            idx++;
        }

        rev(nums, k, n-k-1);
        rev(nums, n-k, n-1);
        rev(nums, k, n-1);

        if(flag) rev(nums, 0, n-1);
        
    }
};
