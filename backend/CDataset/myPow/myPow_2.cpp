class Solution 
{
public:
    double helper(double x,long int n)
    {
        if(n==0)
        {
            return 1;
        }
        if(n==1)
        {
            return x;
        }
        if(n<0)
        {
            return helper(1/x,-n);
        }
        double result=helper(x*x,n/2);
        if(n%2)
        {
            result*=x;
        }
        return result;
    }
    double myPow(double x, int n) 
    {
        return helper(x,n);
    }
};
