class Solution {
public:
    void rotate(vector<int>& nums, int k) {
   int n=nums.size();
        reverse(nums.begin(),nums.end());
queue<int>q;
        for(int i=0;i<n;i++){
            q.push(nums[i]);
        
        }
        while(k!=0){
            q.push(q.front());
            q.pop();
            k--;
        }
        for(int k=0;k<n;k++){
            nums[k]=q.front();
            q.pop();
        }
       reverse(nums.begin(),nums.end());
       
        }
};
