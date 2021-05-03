class Solution {
public:
int reverse(int x) {
    int minimum = INT_MIN, maximum = INT_MAX;
    int res = 0, sign;
    sign = (x<0)?-1:1;
    if (x == minimum)
        return 0;
    x *= sign;  // here check x==minimum first
    while (x) {
        int tmp = sign*res;
        if (tmp>maximum/10 || tmp<minimum/10 || (tmp==maximum/10 && x%10>maximum%10) || (tmp==minimum/10 && x%10<minimum%10))
            return 0;
        res = 10*res + x%10;
        x /= 10;
    }
    return res*sign;
}
};