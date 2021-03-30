class Solution {
public:
    double thisPow(double x, int n) {
       if(n == 0) return 1; 
       double temp = thisPow(x,n/2); 
       temp *= temp;
       if(n%2) temp *= x; 
       return temp;
    }
    double myPow(double x, int n) {
        return n < 0 ? (1/thisPow(x,n)):thisPow(x,n); 
    }
    
};
