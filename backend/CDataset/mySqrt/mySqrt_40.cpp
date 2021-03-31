class Solution
{
public:

int mySqrt(int x) 
{
    long int l = 1;
    long int r = x;
    
    while(l <= r)
    {
        long int mid = (l + r) / 2;
        
        if(mid == x / mid)
        {
            return mid;
        }
        else if(mid < x / mid)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    
    return l - 1;
}
};