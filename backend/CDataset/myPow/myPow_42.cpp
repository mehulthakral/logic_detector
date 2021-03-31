class Solution {
public:

double myPow(double x, int n) {
   
    if(n == 0) return 1;
    if(n == 1) return x;
    if(n == -1) return 1/x;
    
    double res = myPow(x , n/2);
    return (n & 1) ? (n < 0 ? 1/x : x) * res * res : res * res;
    
   
}
};