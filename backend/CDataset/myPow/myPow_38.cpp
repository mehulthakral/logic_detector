class Solution {
public:

    void calcPower(double x, int n, double& acm){
        if(n!=0){
            acm *= x;
            return calcPower(x,(n-1), acm);
        }
    }
    double myPow(double x, int n) {
        
        double acm = 1;
        
        calcPower(x,abs(n),acm);
        
        double pow = ((n>=0)?acm: 1/acm);
        
        return pow;
    }
};