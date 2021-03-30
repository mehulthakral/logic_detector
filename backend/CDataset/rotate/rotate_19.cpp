class Solution {
public:
    //function to reverse the array
    void reversearray(vector<int>& nums,int start,int end){
        while(start<end){
            swap(nums[start], nums[end]);  //using c++ stl swap function
            start++;end--;
        }
    }
    
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;  //for excessive repetition of rotations
		
		/*the order of the function called below is for right rotation of array,in case of left rotation use like:
		 reversearray(nums,0,k-1);
        reversearray(nums,k,n-1);
        reversearray(nums,0,n-1);
		*/
        reversearray(nums,0,n-1);
        reversearray(nums,0,k-1);
        reversearray(nums,k,n-1);
    } 
};
