class Solution 
{
public:
    int mySqrt(int x) 
    {
        if(x==0)
        {
            return 0;
        }
        long long int ans=1;
        for(long long int i=1;i*i<=x;i++)
        {
            ans=i;
        }
        return ans;
    }
};
