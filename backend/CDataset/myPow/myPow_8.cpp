class Solution {
public:
    double myPow(double x, int n) {
        
        long long nn=n;
        if (nn<0){
            nn=-1*nn;
        }
        
        double ans=1.0;
        while(nn){
            
            //odd
            if(nn%2){
                
                ans*=x;
                nn=nn-1;
                
            }else{
                //even
                nn=nn/2;
                x=x*x;
            }
        }
        
        if(n<0){
            return (double)1.0/(double) ans;
        }
        return ans;
        
    }
};
