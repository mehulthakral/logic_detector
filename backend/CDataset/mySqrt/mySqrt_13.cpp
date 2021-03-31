class Solution {
public:
    int mySqrt(int x) {
        if(x==0 || x==1)
            return x;
        if(x==2)
            return 1;
        long l=1, r=x/2+1; // square root of x will always be smaller then (x/2+1)
        long ans = -1;
        while(l<=r) {
            long mid = l+(r-l)/2;
            if(mid*mid==x) // x is perfect square so we return the mid
                return (int)mid;
            else if(mid*mid<x) {
				ans = mid;    // if x is not perfect square, then answer will be the last number whose
							// square is less then x
                l=mid+1;
            }
            else
                r=mid-1;
        }
        return (int)ans;
    }
};
