class Solution {
public:
    int mySqrt(int x)
    {
        long long int low = 1, high = x;
        // 1 and 0 are square roots of itself
        if(x == 0 || x == 1)
            return x;
        
        // Binary Search
        while(low < high)
        {
            // mid point
            long long int mid = (low+high+1)/2;
            // if square of mid is less or equal but sq. of mid+1 is larger then we return smaller one
            // x= 8; 2*2 <= 8 but 3*3 > 8, hence 2 is the answer
            if(mid*mid <= x && (mid+1)*(mid+1) > x)
                return mid;
            // square of mid is larger so right subarray is removed
            if(mid*mid > x)
                high = mid - 1;
            // square of mid is smaller so left subarray is removed
            else
                low = mid + 1;
        }
        return low;
    }
};
