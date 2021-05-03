class Solution {
public:
    int mySqrt(int x) {
        __uint128_t i = 0; 
        for ( ; i <= x; ++i) {
            if ( (i * i) > (long long)x) 
                break;
        }
        
        return i-1;
    }
};