class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int sz = nums.size();
        vector<int> result(sz,0);
        for(int i=0;i<sz;i++){
            result[(i + k)%sz] = nums[i];
        }
        nums = result;
    }
};
