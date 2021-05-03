class Solution {
public:
    int countPrimes(int n)
    {
        std::bitset<1500000> primes;
        primes.set();
        primes.reset(0);
        primes.reset(1);

        for (int i = 2; i * i < n; ++i) {
            if (!primes.test(i))
                continue;
				
            for (int j = i + i; j < n; j += i)
                primes.reset(j);
        }

        int ret = 0;
        for (int i = 2; i < n; ++i) {
            if (primes.test(i))
                ++ret;
        }
        
        return ret;
    }
};
