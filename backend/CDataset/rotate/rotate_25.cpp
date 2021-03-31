class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int orig_size = nums.size();
        k %= orig_size;
        nums.insert(nums.end(),nums.end()-k,nums.end());
        int i=orig_size - k - 1, j = orig_size - 1;
        while(j >= 0){
            nums[j--] = nums[i--];
            if(i == -1){
                i = nums.size()-1;
            }
        }
        nums.resize(orig_size, 0);
    }
};
