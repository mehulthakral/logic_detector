class Solution {
public:
    int mySqrt(int x) {
        if(x <= 1) return x;
        
        int l = 1, r = x/2;
        
        while(l <= r) {
            long long mid = (l+r)/2;
            long long p = mid * mid;
            
            if(p == x) return mid;
            
            if(p < x) l = mid + 1;
            
            else r = mid - 1;
        }
        
        return r;
    }
};
