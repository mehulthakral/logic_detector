class Solution {
public:
    int reverse(int x) {
        int x_cp = abs(x);
        long result = 0;
        while(x_cp) {
            result = result*10+ x_cp%10;
            x_cp /= 10;
        }
        if(result > 2147483647 || result < -2147483648) return 0;
        return x >0 ? result : -result;
    }
};