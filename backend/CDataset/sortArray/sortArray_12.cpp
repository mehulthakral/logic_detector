	// quickSort(nums, 0, nums.size() - 1);
    void quickSort(vector<int>& nums, int l, int r){
        if(l >= r) return;
        int i = l; // cursor for final pivot location 
        for(int j = l; j <= r - 1; j++){ // nums[r] is chosen as the pivot
            if(nums[j] <= nums[r]){
                swap(nums[i], nums[j]);
                i++; // smaller or equal elements go to the left of i 
            }
        }
        swap(nums[i], nums[r]); // after swap, the pivot is nums[i]
        quickSort(nums, l, i - 1);
        quickSort(nums, i + 1, r);
    }

    void swap(int& a, int& b){
        int tmp = a;
        a = b;
        b = tmp;
    }