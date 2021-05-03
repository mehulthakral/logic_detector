class Solution {
public:
    int reverse(int x) {
        if (x == 0) return x;
        int sign = 1;
        long long int sum = 0;
        if (x < 0) 
            x = -x, sign = -1;
        
        while (x > 0)
        {
            sum = sum * 10 + (x % 10);
            x /= 10;
            
            if (sum * sign > INT_MAX || sum * sign < INT_MIN)
                return 0;
        }
        
        return (int)sum * sign;
    }
};
