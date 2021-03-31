class Solution {
public:
    int mySqrt(int x) {
        int lo = 0, hi = x, res;
        while(lo <= hi){
            long long mi = lo + (hi-lo)/2; // to avoid overflow
            if(mi*mi == x)
                return mi;
            else if(mi*mi > x)
                hi = mi-1;
            else{
                lo = mi+1;
                res = mi;
            }
        }
        return res;
    }
};
