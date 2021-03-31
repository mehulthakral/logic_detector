class Solution
{
public:
    double myPow(double x, int n)
    {
        double result;
        if (n == 0)
        {
            return 1;
        }
        result = myPow(x, n / 2);
        if (n % 2 == 0)
        {
            return result * result;
        }
        else {
            return n > 0 ? x * result * result  : result * result / x;
        }
    }
};

