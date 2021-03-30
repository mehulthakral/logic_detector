class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n<=1) return 0;
        
        int jumps=0, currreach=0, maxreach=0;
        for(int i=0; i<n; i++){
            if(currreach<i){
                jumps++;
                currreach=maxreach;
            }
            maxreach=max(maxreach, i + nums[i]);
        }
        return jumps;
        
    }
};