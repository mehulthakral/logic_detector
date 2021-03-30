class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        while(k--){
            int temp = nums[nums.size()-1];
            for(int i = nums.size()-2; i>= 0 ;i--){
                nums[i+1] = nums[i];
            }
            nums[0] = temp;
        }   
    }
};
