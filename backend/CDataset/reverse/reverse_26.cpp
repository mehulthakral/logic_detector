class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while(x) {
            bool checkPosNotOverflow = x > 0 && res <= INT_MAX / 10 && res * 10 <= INT_MAX - x % 10;
            bool checkNegNotOverflow = x < 0 && res >= INT_MIN / 10 && res * 10 >= INT_MIN - x % 10;
            if (checkPosNotOverflow || checkNegNotOverflow) res = res * 10 + x % 10;
            else return 0;
            x /= 10;
        }
        return res;
    }
};
