class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) return x; // edge case 
        int lo = 0, hi = x/2; 
        while (lo < hi) {
            int mid = (lo + hi + 1) >> 1; 
            if (x/mid < mid) {
                hi = mid - 1; 
            } else {
                lo = mid; 
            }
        }
        return lo; 
    }
};
