class Solution {
   public:
    int mySqrt(int x) {
        int res = 0;
        for (int mask = 1 << 15; mask != 0; mask >>= 1) {
            int next_try = res | mask;
            if (next_try <= x / next_try) {
                res = next_try;
            }
        }
        return res;
    }
};
