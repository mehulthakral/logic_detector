class Solution {
public:
    bool isPrime(int num)
    {
        for(int i=2;i*i<=num;i++)
        {
            if(num%i==0)
              return false;
            
        }
        return true;
    }
    
    int countPrimes(int n) 
    {
      if(n==0 || n==1)
          return 0;
      int c=0;
        
      for(int i=2;i<n;i++)
      {
          if(isPrime(i))
              c++;
      }
        return c;
        
    }
};
