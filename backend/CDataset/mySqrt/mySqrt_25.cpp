/*
    https://leetcode.com/problems/sqrtx/submissions/
    
    We use binary search for this. We set the lower limit as 0 and upper limit as n/2.
    n/2 ensures that the range covers all possible candidates for sq root, since sq root is
    m * m, so n/2 * n/2 > n and hence covers all.
    
    TC: O(logn)
*/

class Solution {
public:
    int mySqrt(int x) {
        if(x <= 1)
            return x;
        int low = 0, high = ceil(x / 2);
        
        while(low < high) {
            // rounded ceil
            int mid = low + (high - low + 1) / 2;
            long long sq = (long long)mid * mid;
            if(sq <= x)
                low = mid;
            else
                high = mid - 1;
        }
        
        return low;
    }
};
