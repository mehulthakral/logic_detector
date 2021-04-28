class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        /*
        if(nums.size()==1){
             for(auto vec:nums) cout<<vec<<" ";
            cout<<endl;
            return;
        }
        */
        if(nums.size()<k){
            while(k){
                int pos=nums.size()-1;
                int val=nums[pos];
                nums.erase(nums.begin()+pos);
                nums.insert(nums.begin()+0,val);
                k--;
            }
            /*
            for(auto vec:nums) cout<<vec<<" ";
            cout<<endl;
            */
            return;
        }
        queue<int> pq;
        while(pq.size()<k){
            int pos=nums.size()-1;
            pq.push(nums[pos]);
            nums.erase(nums.begin()+pos);
        }
        while(!pq.empty()){
            nums.insert(nums.begin()+0,pq.front());
            pq.pop();
        }
        /*
        for(auto vec:nums) cout<<vec<<" ";
        cout<<endl;
        */
    }
};
