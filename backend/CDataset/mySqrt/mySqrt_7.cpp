class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;
        int l = x;
        while (l > x / l) 
            l = l / 2 + x / l / 2 + (l % 2 && (x / l) % 2);
        return l;
    }
};
