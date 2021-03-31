class Solution {
public:
    vector<int> primes = {2, 3, 5, 7, 11};
    bool isPrime(int n) {
        int lmt = sqrt(n), i = 1;
        while (primes[i] <= lmt) {
            if (n % primes[i++] == 0) return false;
        }
        return true;
    }
    int countPrimes(int n) {
        if  (primes.back() < n) {
            int lastBase, a, b;
            if ((primes.back() - 1) % 6 == 0) lastBase = primes.back() + 5;
            else {
                lastBase = primes.back() + 7;
                if (isPrime(primes.back() + 2)) primes.push_back(primes.back() + 2);
            }
            while (primes.back() < n) {
                a = lastBase - 1;
                b = lastBase + 1;
                if (isPrime(a)) primes.push_back(a);
                if (isPrime(b)) primes.push_back(b);
                lastBase += 6;
            }
        }
        return lower_bound(begin(primes), end(primes), n) - begin(primes);
    }
};
