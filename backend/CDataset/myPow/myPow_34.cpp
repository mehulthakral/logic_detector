class Solution {
public:
    double myPow(double x, int n) {
        long time=2;
        long nn=n;
        nn=nn<0?-nn:nn;
        double res=n<0?1/x:x;
        double ans=nn&1?res:1;
        while(time<=nn){
            res*=res;
            if(nn&time)ans*=res;
            time<<=1;
        }
        return ans;
    }
};
