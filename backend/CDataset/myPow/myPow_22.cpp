class Solution {
public:
    double myPow(double x, int n) {
        bool flag = n < 0;
        double res = 1;
        while (n != 0)
        {
        if (n % 2)
            res = res * x;
        x = x * x;
        n /= 2;
            
        }
        return flag ?1/res:res; 
    }
    
};
