class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size()-1);
        return nums;
    }
    void quickSort(vector<int>& nums, int left, int right){
        if(left < right){
            // to make pivot rightmost element random
            int random_idx = left + (rand() % (right-left));
            swap(nums[random_idx],nums[right]);
            
            int pivot = left;
            for(int j = left; j <= right - 1 ; j++){
                if(nums[j] < nums[right]){
                    swap(nums[pivot++], nums[j]);
                }
            }
            swap(nums[pivot], nums[right]);
            quickSort(nums, left, pivot-1);
            quickSort(nums, pivot+1, right);
        }
    }
    void swap(int& i, int& j){
        int temp = i;
        i = j;
        j = temp;
    }
};
