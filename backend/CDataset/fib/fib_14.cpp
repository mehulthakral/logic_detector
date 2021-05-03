class Solution 
{
private:
  int cache[31];
public:
    Solution()
    {
        cache[0] = 0;
        cache[1] = 1;
        for(int i=2;i<31;i++)
            cache[i]=-1;
    }
    
    int fib(int N) 
    {
      if(cache[N] != -1)
      {
        return cache[N];   
      }
      cache[N] = fib(N-1)+fib(N-2);

      return cache[N];
    }
};
