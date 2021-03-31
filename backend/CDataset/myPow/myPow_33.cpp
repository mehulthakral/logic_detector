class Solution {
public:
    double myPow(double x, long long n) {
        if(n == 0) return 1;

        double result = 1;
        long long tmp = abs(n);
        while(tmp) {
            if(tmp % 2 == 1) {
                result *= x;
                tmp -= 1;
            } else {
                x *= x;
                tmp /= 2;
            }
        }
        return (n > 0)? result: 1/result;
    }
};
