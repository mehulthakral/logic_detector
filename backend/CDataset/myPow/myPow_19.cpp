class Solution {
public:
    double myPow(double x, int n) {
        double res=1;
        bool f=0;
        if(n<0)
            f=1;
        while(n)
        {
            if(n%2)
                res=res*x;
            x=x*x;
            n=n/2;
        }
        if(f)
            return 1/res;
        return res;
    }
};
