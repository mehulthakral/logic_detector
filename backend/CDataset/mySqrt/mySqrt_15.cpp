class Solution {
public:
    int mySqrt(int x) {
        int low = 1, high = x;    
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            if(pow(mid, 2) == x)
                return mid;
            if(pow(mid, 2) < x)
                low = mid + 1;
            if(pow(mid, 2) > x)
                high = mid - 1;
        }
		return low-1; //if the loop terminates, the value before with decimal places would have been the sq root
    }
};
