class Solution
{
public:

int mySqrt(int x) 
{
    if(x == 0) return 0;
    if(x == 1) return 1;
    
    double res = x/2;
    
    for(int k = 0; k < 20; k++)
    {
        res = 0.5 * (res + x/res);
    }
    
    return res;
}
};