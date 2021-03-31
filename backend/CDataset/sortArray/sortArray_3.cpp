class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        
        priority_queue<int,vector<int>,greater<int>>minh;
        vector<int>v;
        
        for(int i=0;i<n;i++){
            minh.push(nums[i]);
        }
        for(int j=0;j<n;j++){
              v.push_back(minh.top());
            minh.pop();
            
        }
        return v;
    }
};
