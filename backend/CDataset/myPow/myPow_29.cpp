class Solution {
public:
    double myPow(double x, int n) {
        double ans=1,k=0;
        long n1=n;
        if(n1<0){
            k=1;
            n1=-n1;
        } 
        while(n1>=1){
            if(n1%2!=0)
                ans*=x;
            x*=x;
            n1=n1/2;
        }
        if(k==1)
            return (1/ans);
        return ans;
    }
};
