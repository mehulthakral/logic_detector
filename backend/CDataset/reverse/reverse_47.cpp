class Solution {
public:
    int reverse(int x) {
        int tag = x < 0 ? -1 : 1;
        unsigned long temp = 0;

        x *= tag;
        for( ; x; x /= 10 )
        {
            temp = temp * 10 + x % 10;
            if( temp > INT_MAX )
                return 0;
        }
        return temp * tag;
    }
};