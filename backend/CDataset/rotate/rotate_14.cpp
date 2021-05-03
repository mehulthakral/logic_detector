class Solution {
public:
void rotate(vector<int>& nums, int k) {
        int size;
        size = nums.size();
      
        if(k>size)
            k = abs(size-k)%size;
        
      /*  for(i=0; i<k; i++)
            nums.emplace(nums.begin(), nums[size-1]);       //emplace is expensive, run time very high
        nums.resize(size); */
        
     /*   for(i=0; i<size-k; i++)
            nums.push_back(nums[i]);
        nums.erase(nums.begin(), nums.begin()+size-k); */
        
        reverse(nums.begin(), nums.end());      //reverse the whole array
        reverse(nums.begin(), nums.begin()+k);      //reverse the numbers from beginning to kth position
        reverse(nums.begin()+k, nums.end());        //reverse the rest of the array to make it original
    }
};