class Solution { // Binary Search - Lightweight
public:
    double calculateSqrt(double x, double n){
        if(abs(x/n-n)<0.000001) return n;
        return calculateSqrt(x,(n+x/n)/2); // better n is (n+A/n)/2
    }
    int mySqrt(int x) {
        return (int)calculateSqrt(x,1);
    }
};
