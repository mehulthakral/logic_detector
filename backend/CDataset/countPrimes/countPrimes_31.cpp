class Solution {
public:
  int countPrimes(int n) {
    static vector<int> sieve;
    if (n <= 2) return 0;
    if (sieve.size() < n/2) {
      sieve.resize(n/2, 1);
      for (int p = 3; p*p < n; p += 2) {
        if (!sieve[p/2]) continue;
        int pp = max(sieve[p/2], p*p);
        for (; pp < n; pp += 2*p)
          sieve[pp/2] = 0;
        sieve[p/2] = pp;
      }
    }
    int result = 0;
    for (int i = 0; i < n/2; ++i)
      result += !!sieve[i];
    return result;
  }
};
