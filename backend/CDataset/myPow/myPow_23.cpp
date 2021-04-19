class Solution {
public:
double solve(double x,long n) {
        if(n==0) return 1.0;
        if(n==1) return x;
        if(n%2==0) return solve(x*x,n/2);
        return x*solve(x*x,(n-1)/2);
    }
    double myPow(double x, int n) {
        long nn=n;
        if(n<0) nn=-nn;
        double ans=solve(x,nn);
        if(n<0) return 1.0/ans;
        return ans;
    }
};