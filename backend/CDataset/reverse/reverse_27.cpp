class Solution {
public:
    int reverse(int x) {
        bool isNegative{}; // False by default
        int newInt{};
        
        if (x < 0)
        {
            isNegative = true;
            if (x == numeric_limits<int>::min()) return 0; // If it's the lowest number, return 0
            x *= -1; // This will overflow if we are given the smallest potential number.
			// But by the time we reach here we've already returned 0. Otherwise this multiplication won't
			// give us any issues. We want to turn all negative numbers positive to not deal with negatives
			// in multiplication below.
        }
        
		// Reverse an integer
        while (x)
        {
            // Check integer overflow
            if (newInt > INT_MAX / 10 || newInt < INT_MIN / 10) return 0;
            newInt = newInt * 10 + x % 10;
            x /= 10;
        }
        // Restore negative if the number was originally negative
        return isNegative ? -1 * newInt : newInt;
    }
};
