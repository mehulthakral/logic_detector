class Solution {
public:
    double myPow(double x, int n) 
    {
        // .. corner case
        if(n == 0)
        {
            return 1;
        }
        // .. just to quickly return
        if(x == 1)
        {
            return 1;
        }
        
        // For all other cases
        
        double result = 1;
        
        // Administration data to fast forward the calculation by reducing the required number of iterations by half.
        double inc = x;
        unsigned int inc_counter = 1;
        
        unsigned int n_t = std::abs(n);
        while(n_t > 0)
        {
            if(n_t < inc_counter)
            {
                inc = x;
                inc_counter = 1;
            }
            
            result *= inc;
            n_t -= inc_counter;
            
            inc *= inc;
            inc_counter+=inc_counter;
        }
        
        // final result based on sign(n)
        return (n > 0) ? result : 1/result;
    }
};
