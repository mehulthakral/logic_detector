class Solution {
public:
    int mySqrt(int n)
    {       
        if (n < 2) { return n; }
        
        int l = 0;
        int r = n / 2;
        int sqrt_n = n / 2;  // initial guess
		
        while (r - l > 1)
        {
            if (n / sqrt_n < sqrt_n) { r = sqrt_n; }
            else if (n / sqrt_n > sqrt_n) { l = sqrt_n; }
            else { return sqrt_n; }  // if (n / sqrt_n == sqrt_n)
            sqrt_n = (r + l) / 2;    
        }  
        return sqrt_n;        
    }
};
