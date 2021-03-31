class Solution {
public:
    int reverse(int x) {
        if (!x)
            return 0;
        string rev = "";
        bool negative = x < 0 ? true : false;
        long y = x;
        try
        {
            y = abs(y);
            // Reverse the digits
            while (y)
            {
                rev += to_string(y % 10);
                y /= 10;
            }
            // Add a minus sign if the original number was negative
            return negative ? stoi(rev.insert(0, 1, '-')) : stoi(rev);
        }
        // For cases of overflow
        catch(...)
        {
            return 0;
        }
    }
};
