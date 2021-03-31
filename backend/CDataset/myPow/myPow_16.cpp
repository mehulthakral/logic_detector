class Solution {
public:
    double myPow(double x, int n) {
        unsigned int exp = abs( static_cast<long>( n ) );
        double retVal = 1.0;
        
        double pow = x;
        while( exp > 0 ) {
            if( exp & 0x1 ) retVal *= pow;
            exp = exp >> 1;
            pow *= pow;
        }
        
        return n > 0 ? retVal : 1.0 / retVal;
    }   
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Pow(x, n).
// Memory Usage: 5.9 MB, less than 66.73% of C++ online submissions for Pow(x, n).
