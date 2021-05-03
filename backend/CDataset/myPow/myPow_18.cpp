class Solution {
public:
    double myPow(double x, int n) {
        long n2 = (long)n;
        if (n2 < 0) {n2 = -n2; x = 1/x;}
        if (n2 == 0)
            return 1;
        return (n2 % 2 == 0) ? myPow(x*x, n2/2) :  myPow(x*x, n2/2)*x;
    }
};
