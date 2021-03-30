class Solution {
 public:
    int reverse(int x) {
        long result = 0;           // Final result
        long op = x < 0 ? -1 : 1;  // Get the operator

        long tmp = abs((long)x);  // Avoid too many type conversions and work with positive number
        while (tmp) {             // When tmp is zero, stops
            result += tmp % 10;   // Get the last number
            result *= 10;
            tmp /= 10;
        }
        result /= 10;  // Remove the last zero

        return result > (long)INT_MAX ? 0 : result * op;
    }
};