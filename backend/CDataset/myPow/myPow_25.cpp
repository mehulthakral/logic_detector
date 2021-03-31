class Solution {
public:
    double myPow(double x,long long int n) {
        double ans=1.00;
        bool n_pos=true;
        if(n<0)
        {
            n_pos=false;
            n*=-1;
        }
        while(n)
        {
            if(n&1) ans*=x;         // if n is odd  
            n>>=1;                    // n=n/2
            x*=x;
        }
		if(n_pos)                        // if n is positive
            return ans;
		return (1.0/ans);           // if n is  negative 
    }
};
