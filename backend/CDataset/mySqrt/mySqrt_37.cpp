class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        if (x < 3) return 1;
        __uint128_t init = 0;
        __uint128_t last = x;
        __uint128_t old_mid = 0;
        __uint128_t mid = 0;
        while(1) {
            mid = (init + last) / 2;
            if (old_mid == mid) break;
            if (mid * mid <= x) {
                init = mid;
            } else {
                last = mid;
            }
            old_mid = mid;
        }
        return (int)mid;
    }
};