class Solution
{
public:
    int reverse(int x)
    {
        if(x == 0)
            return 0;
            
        long result = 0;  
        
        while(x % 10 == 0)
            x /= 10;
        while(x)
        {
            result = result*10 + x % 10;
            
            if(result >= INT_MAX || result<= INT_MIN)
                return 0;
            x /= 10;
        }
        
        return result;
    }
};