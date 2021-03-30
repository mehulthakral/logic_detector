class Solution {
   public:
    int mySqrt(int x) {
        if (x < 2) {
            return x;
        }
        int r = x;
        while (r > x / r) {
            r = r / 2 + x / r / 2;
        }
        return r + 1 > x / (r + 1) ? r : r + 1;
    }
};
