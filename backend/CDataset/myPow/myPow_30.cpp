class Solution {
public:
    double myPow(double x, long long n) {
        if (n >= 0) {
            if (n == 0)
                return 1;
            double half_power = myPow(x, n/2);
            if (n % 2) {
                return half_power * half_power * x;
            } else {
                return half_power * half_power;
            }
        } else {
            return 1 / myPow(x, -n);
        }
    }
};
