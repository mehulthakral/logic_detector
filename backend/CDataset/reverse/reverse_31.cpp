// 1. Use C++ INT_MAX/INT_MIN (defined similar to boundaries of the problem)
// 2. Multiply 'ret' by 10 to add another zero each iteration
// 3. Strip the last digit from 'x' with the modulus operator
// 4. Add the stripped off last digit to 'ret'
// 5. If 'x' divided by 10 == 0, then we have removed all digits from 'x'.
class Solution {
public:
    int reverse(int x) {
        long long ret = 0;
        while (x != 0) {

            // Iteration    |    1      |    2      |    3
            // ret = 0      | 0 + 3 = 3 |  30+2=32  | 320+1=321
            //  x  = 123    | 123/10=12 |  12/10=1  | 1/10=0 ==>>> exit loop

            ret = (ret*10) + (x%10);
            x /= 10;

            if (abs(ret) > INT_MAX) {
                return 0;
            }
        }
        return ret;
    }
};
