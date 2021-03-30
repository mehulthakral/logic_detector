class Solution {
public:
    double calPow(double x, int n) {
        if(n==0) return 1;
        
        if(n%2==0){
            double y = calPow(x,n/2);
            return y*y;
        }
        else{
            double y = calPow(x,(n-1)/2);
            return y*y*x;
        }
    }
    
    double myPow(double x, int n) {
        if(n==0) return 1;
        if(x==0) return 0;
        
        if(n<0) {
            if(n==INT_MIN)
                return 1/x*calPow(1/x,INT_MAX);
            else
                return calPow(1/x,abs(n));
        }
        else return calPow(x,n);
    }
};
