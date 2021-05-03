class Solution {
public:
    int mySqrt(int x) {    
        auto i = 1;
        while (x / i > i) i++;
        return x / i;
    }
};
