class Solution {
public:
    int reverse(int x) {
        int a = r(x);
        if(r(a) != x && x % 10 != 0) return 0;
        else return a;
    }
    
    int r(int x)
    {
        int r = 0;
        while(x != 0)
        {
            r *= 10;
            r += x % 10;
            x /= 10;
        }
        return r;
    }
};
