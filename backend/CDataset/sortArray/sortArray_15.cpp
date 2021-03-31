	// insertionSort(nums);
	void insertionSort(vector<int>& nums){
        if(nums.size() == 0 || nums.size() == 1) return;
        for(int i = 1; i < nums.size(); i++){
            int tmp = nums[i];
            int j = i - 1;
            while(j >= 0 && nums[j] > tmp){
                nums[j + 1] = nums[j];
                j--;
            }
            nums[j + 1] = tmp;
        }
    }