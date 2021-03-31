class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> v;
        int n = nums.size();
        
    
        if(k==0 || n == 1 ) {
            return;
        }
        
        if(k >= n) {
            k = k-n;
        }
        
        for(int j = n-k; j < n; j++) {
               v.push_back(nums[j]);
           }
        
         for(int z = 0; z < n-k; z++) {
               v.push_back(nums[z]);
           }
        
      
        for(int i = 0; i < n; i++) {
            nums[i] = v[i];
        }
    }
};
