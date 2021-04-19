class Solution {
public:
int mySqrt(int x) {
        if(x<=0) return 0;
       return pow(2,0.5*log2(x)) ;
    }
};