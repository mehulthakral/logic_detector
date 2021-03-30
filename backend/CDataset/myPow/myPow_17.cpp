class Solution {
public:
    double go(double a, long long b){
        if(b==1) return a;
        if(b==0) return 1;
        if(b<0) return go(1/a, -1*b);
        if(b&1) return a*go(a,b-1);
        return go(a*a,b/2);
    }
    double myPow(double x, int n) {
        double ans=1;
        ans= go(x,n);
        return ans;
    }
};
