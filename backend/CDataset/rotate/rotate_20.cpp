class Solution {
public:
    void rev(vector<int> &nums,int st,int en){
        while(st<en){
            swap(nums[st],nums[en]);
            st++;
            en--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k%=n;
        rev(nums,0,n-1);
        rev(nums,0,k-1);
        rev(nums,k,n-1);
    }
};
