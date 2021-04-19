class Solution {
public:
int reverse(int x) {
        if (x == 0) {
            return 0;
        } else {
            int res = 0;
            int _x = abs(x);
            int flag = _x / x;
            while (_x > 0) {
                int curr = _x % 10;
                //in case overflow
                if (res > (INT_MAX - curr) / 10) {
                   return 0;
                } else  {
                    res  = res * 10 + curr;
                    _x = _x / 10;
                }
            }
            return flag * res;
        }
    }
};