class Solution {
public:
double myPow(double x, int n) {
        // T = O(log2(N)) & S = O(1)
        double ans = 1.00000;
       long long int a = n;
        if(n < 0) a = -1*a;
        while(a > 0) {
            if(a % 2 == 1) {
                ans = ans*x;
                a = a-1;
            } else {
                x = x*x;
                a = a/2;
            }
        }
        if(n < 0) ans = (double)1.00000/(double)ans;
        return ans;
    }
};