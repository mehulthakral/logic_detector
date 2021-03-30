class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
        int l=nums.size()-k;
        //cout<<l<<endl;
        reverse(nums.begin(),nums.begin()+l);
        reverse(nums.begin()+l,nums.end());
        reverse(nums.begin(),nums.end());
    }
};

