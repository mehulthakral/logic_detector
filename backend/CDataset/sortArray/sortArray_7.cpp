class Solution {
public:
    void swap(int &a, int &b)
    {
        int t=a;
        a = b;
        b = t;
    }
    int partition(vector<int>& nums, int low, int high)
    {
        int i=low-1, pivot=nums[high];
        for(int j=low; j<high; j++)
        {
            if(nums[j]<=pivot) 
            {
                i++;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i+1], nums[high]);
        return i+1;
    }
    void quickSort(vector<int>& nums, int low, int high)
    {
        if(low<high)
        {
            int pivot=partition(nums, low, high);
            quickSort(nums, low, pivot-1);
            quickSort(nums, pivot+1, high);
        }
    }
    vector<int> sortArray(vector<int>& nums) 
    {
        int n=nums.size(), low=0, high=n-1;
        quickSort(nums, low, high);
        return nums;
    }
};
