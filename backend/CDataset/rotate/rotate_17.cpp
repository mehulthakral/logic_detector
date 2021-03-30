class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k%nums.size() && nums.size()>1 ){
            int t = nums.size()-k%nums.size();
            for(int i= 0;i<t;i++){
                nums.push_back(nums[i]);
            }
            nums.erase(nums.begin(),nums.begin() + t);
        }
    }
};
