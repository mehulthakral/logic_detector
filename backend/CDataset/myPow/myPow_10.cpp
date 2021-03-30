class Solution {
public:
    double myPow(double x, int n) {
        if(n>0) return posPow(x,n) ;
        return negPow(x,-1LL*n);
    }
    
    double posPow(double x, int n){
        if(!n)return 1.00;  
        double res = posPow(x,n/2) ;
        res = res*res ;
        if(n&1) res*= x ;
        return res ;
    }
    
    double negPow(double x, long long int n){
        if(!n) return 1.00 ;        
        double res = negPow(x,n/2) ;
        res = res*res ;
        if(n&1) res/=x ;
        return res ;
    }
};
