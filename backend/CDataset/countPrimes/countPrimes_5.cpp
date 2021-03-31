//Sieve of Eratosthenes

class Solution {
public:
    int countPrimes(int n) {
        // start from two bcz 1 and 0 are non prime
        if(n==0 || n==1) return 0;
        // initialize all elements from 2 to n-1 --> true i.e assuming they are --> prime
        vector<bool> v(n-1,true);
              
        // loop untill i*i < n --> bcz the multiples of i are already altered
        for(int i=2;i*i<n;i++)
        {   // only proceed if set to true
            if(v[i])
            // loop an alter all the mutiples to false
            for(int j=2;j*i<n;j++)
           {
               v[i*j]=false;
           }           
        }
        int c=0;
        // count and return the elements not yet altered -- > which implies they are prime
        for(int i=2;i<n;i++) if(v[i]==true) c++;
        return c;
    }
};
