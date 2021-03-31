class Solution {
   public:
    int mySqrt(int x) {
        if (x < 2) {
            return x;
        }
        int l = 1;
        int r = x;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (m > x / m) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l - 1;
    }
};
