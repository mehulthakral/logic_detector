class Solution {
public:
    int countPrimes(int n) {
        vector<int> a(n,1);
        for (int i = 2; i < n; ++i)
            if (a[i] == 1)
                for (int j = i * 2; j < n; j += i)
                    a[j] = 0;
        int cnt = 0;
        for (int i = 2; i < n; ++i)
            if (a[i] == 1)
                ++cnt;
        return cnt;
    }
};
