class Solution {
public:
    int countPrimes(int n) {
        vector<bool> sieve(n, true);
        for (int i = 2; i*i < n; ++i) {
            if (sieve[i]) {
                for (int j = 2*i; j < n; j += i) {
                    sieve[j] = false;
                }
            }
        }
		int count = 0;
        for (int i = 2; i < n; ++i) {
            if (sieve[i]) ++count;
        }
        return count;
    }
};