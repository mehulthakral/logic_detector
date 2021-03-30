class Solution {
public:
    unsigned long long mySqrt(unsigned long long x)
    {
        unsigned long long l = 0;
        unsigned long long r = x;
        unsigned long long m, ans = 0;

        if (x <= 1) {
            return x;
        }

        while (l<=r) {
            m = l + (r - l) / 2;

            if (m * m == x) {
                return m;
            }
            else if (m * m < x) {
                ans = m;
                l = m+1;
            }
            else {
                r = m-1;
            }
        }
        return ans;
    }
};
