double myPow(double x, int n) {
       double res = 1.0;
       
       // Corner case.
       if(x == 0)
           return res;
       
       bool isNeg = n < 0 ? true : false;
       long N = abs(n); // Use long to prevent overflow when n = INT_MIN because we divide n by half.
       
       while(N){
           if(N & 1)
               res = isNeg ? res / x : res * x;
           x = x * x;
           N >>= 1;
       }
       
       return res;
   }
