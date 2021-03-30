class Solution {
public:
    // Merges two arrays by sorting 
    void mergeArray(vector<int> &A, int left, int mid, int right) {
        // Create temp arrays
        int Lsize = mid - left + 1;
        int Rsize = right - mid;
        vector<int> L(Lsize);
        vector<int> R(Rsize);
        // Copy unsorted data from A to temp arrays
        for (int i = 0; i < Lsize; i++) {
            L[i] = A[left + i];
        }
        for (int j = 0; j < Rsize; j++) {
            R[j] = A[mid + j + 1];
        }
        // Merge temp arrays back into A
        int l = 0; // Left Temp Array
        int r = 0; // Right Temp Array
        int k; // Merged Original Array
        for (k = left; k <= right && l < Lsize && r < Rsize; k++) {
            if (L[l] <= R[r]) {
                A[k] = L[l];
                l++;
            } else {
                A[k] = R[r];
                r++;
            }
        }
        while (k <= r && l < Lsize && r < Rsize) {
            if (L[l] <= R[r]) {
                A[k] = L[l];
                l++;
            } else {
                A[k] = R[r];
                r++;
            }
            k++;
        }
        // Copy If Left Temp has any remaining elements
        while (l < Lsize) {
            A[k] = L[l];
            l++;
            k++;
        }
        // Copy If Right Temp has any remaining elements
        while (r < Rsize) {
            A[k] = R[r];
            r++;
            k++;
        }
    }

    // Merge sort
    void mergeSort(vector<int> &A, int left, int right) {
        if (left < right) {
            int mid = (left + right) / 2;
            // Left Sub-Array
            mergeSort(A, left, mid);
            // Right Sub-Array
            mergeSort(A, mid + 1, right);
            // Merge Sub-Arrays
            mergeArray(A, left, mid, right);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};
