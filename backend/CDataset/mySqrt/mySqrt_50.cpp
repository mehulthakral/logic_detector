class Solution {
public:
    int mySqrt(int x) {
        long int r = x;
        while (pow(r, 2) > x) {
            r = (r + x / r) / 2;
        }
        return r;
    }
};
