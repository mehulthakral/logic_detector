class Solution {
public:
    void merge(vector<int>& nums, int low, int mid, int high)
    {
        vector<int> t(high-low+1);
        int i=0, j=low, k=mid+1; 
        while(j<=mid && k<=high)
        {
            if(nums[j]<=nums[k])
            {
                t[i] = nums[j];
                j++;
            }
            else 
            {
                t[i] = nums[k];
                k++;
            }
            i++;
        }
        
            while(j<=mid) t[i] = nums[j], i++, j++;
            while(k<=high) t[i] = nums[k], i++, k++;
            for(int i=low; i<=high; i++)
            {
                nums[i] = t[i-low];
            }
    }
    void mergeSort(vector<int>& nums, int low, int high)
    {
        if(low<high) 
        {
            int mid=low+(high-low)/2;
            mergeSort(nums, low, mid);
            mergeSort(nums, mid+1, high);
            merge(nums, low, mid, high);
        }
    }
    vector<int> sortArray(vector<int>& nums) 
    {
        int n=nums.size();
        int low=0, high=n-1;
        mergeSort(nums, low, high);
        return nums;
    }
};
