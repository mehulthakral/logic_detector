class Solution {
   public:
    int mySqrt(int x) {
        union {
            float f;
            int i;
        } u;

        u.f = x;
        u.i = 0x5f375a86 - (u.i >> 1);

        float f = 1 / (u.f * (1.5F - 0.5F * x * u.f * u.f));

        // Once Newton method
        f = f / 2 + x / f / 2;

        int r = f;
        return r * r > x ? r - 1 : r;
    }
};
