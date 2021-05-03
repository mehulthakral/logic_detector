class Solution {
public:
    int reverse(int x) {
        int r{0};
        
        while (x / 10) {
            r *= 10;
            r += x % 10;
            x /= 10;
        }
        
        if (r / (INT_MAX / 10 + 1)) {
            return 0;
        }
            
        return r * 10 + x;
    }
};