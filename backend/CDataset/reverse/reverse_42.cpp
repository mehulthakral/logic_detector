class Solution {
public:
    int reverse(int x) {
        if (x == 0) return x;
        int sum = 0, low = 0, sign = 1;
        if (x < 0) 
            x = -x, sign = -1;
        
        while (x > 0)
        {
            low = x % 10;
            if ((INT_MAX - low) / 10 < sum)
                return 0;
            sum = sum * 10 + low;
            x /= 10;

        }
        
        return sign * sum;
    }
};