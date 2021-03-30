class Solution {
public:
    int reverse(int x) {
        long result = 0L;
        while (x) {
            result = result * 10 + (x % 10);
            x /= 10;
        }
        
        return (result >= (long) INT_MAX || result <= (long) INT_MIN) ? 0 : result;
    }
};
