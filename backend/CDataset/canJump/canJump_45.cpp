class Solution {
public:
	bool canJump(vector<int>& nums) {
		int cur=0;
		for(int i=0;i<nums.size()-1;i++){
			if(i+nums[i]>cur){
				cur=i+nums[i];
			}
			if(nums[i]==0){
				if(cur<=i){
					return false;
				}
			}
		}
		return true;
	}
};