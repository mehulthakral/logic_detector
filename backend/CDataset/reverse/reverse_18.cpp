class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        int ori = x;

        bool zeroFlag = true;

        while(ori!=0)
        {
            if (ori % 10 == 0 && zeroFlag)
            {
                ori = ori / 10;
                continue;
            }

            if (rev > INT_MAX / 10 || rev < INT_MIN / 10)
                return 0;

            rev = rev * 10 + (ori % 10);
            ori = ori / 10;
            zeroFlag = false;
        }

        return rev;
    }
};
