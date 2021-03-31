class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0) return false;
        if (x==0) return true;
        long y = 0;
        long xo = x;
        while(x>0) {
            y = y*10 + x%10;
            x/=10;
        }
        return xo == y;
    }
};
