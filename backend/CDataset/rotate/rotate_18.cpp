class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        if(k>n) k-=n;
        if(n==k||!k) return;
        reverse(nums.begin(),nums.end());
        int i=0;
        while(i!=k)
            nums.push_back(nums[i++]);
        reverse(nums.begin(),nums.end());
        nums.resize(n);
    }
};
