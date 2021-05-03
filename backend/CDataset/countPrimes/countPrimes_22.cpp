class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        vector<int> primes{2};
        for (int i = 3; i < n; i += 2) {
            for (const int &p : primes) {
                if (p*p > i) {
                    primes.push_back(i);
                    break;
                }
                if (!(i % p)) break;
            }
        }
        return primes.size();
    }
};