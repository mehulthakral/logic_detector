class Solution
{
private:

bool isPrime(int n)
{
    if(n == 0) return false;
    if(n == 1) return false;
    if(n == 2) return true;
    
    for(int i = 2; i * i <= n; i++)
    {
        if(n % i == 0) return false;
    }
    
    return true;
}

public:

int countPrimes(int n) 
{
    int res = 0;
    
    for(int i = 0; i < n; i++)
    {
        if(isPrime(i)) res++;
    }
    
    return res;
}
};