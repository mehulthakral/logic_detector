class Solution {
public:
    int mySqrt(int x) {
        long long l = 1, r = x;
        while(l <= r){
            long long m = (l + r) / 2;
            if (m == x / m) return m;
            else if (m * m > x) r = m - 1;
            else l = m + 1;
        }
        return l - 1;
    }
};
