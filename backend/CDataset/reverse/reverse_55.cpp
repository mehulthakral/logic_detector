class Solution {
public:
    int reverse(int x) {
        int result = 0;
        while (x != 0)
        {
            int a = x % 10;
            if (a > 0 && (result > INT_MAX/10 || (result == INT_MAX/10 && a > 7))) return 0;
            if (a < 0 && (result < INT_MIN/10 || (result == INT_MIN/10 && a < -8))) return 0;

            result = result*10 + a;
            x /= 10;
        }
        return result;
    }
};