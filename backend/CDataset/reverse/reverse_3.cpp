/**
    https://leetcode.com/problems/reverse-integer/
    
    TC: O(1), 32 bit numbers have a limited num of digits
    SC: O(1)
**/
class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        // instead of checking separately for negative and 
        // positive number, we can combine the checks by making the num +ve.
        // in case the the x is neg, then the max limit 
        // is INT_MAX + 1, but since we are limited to 32bits we can
        // use the unsigned var to store just +1 of INT_MAX
        unsigned int max_limit = x < 0 ? (unsigned int)INT_MAX + 1 : INT_MAX;
        bool neg = x < 0;
        // take absolute value for calc
        x = abs(x);
        
        // simple reversal with overflow checks
        while(x) {
            // overflow due to multiplcation
            if(rev > max_limit / 10)
                return 0;
            rev *= 10;
            // overflow due to addition
            if(rev > max_limit - x % 10)
                return 0;
            rev = rev + x % 10;
            x /= 10;
        }
        return rev * (neg ? -1 : 1);
    }
};
