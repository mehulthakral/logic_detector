class Solution {
public:
    int fib(int N) {
        if(N == 0) return 0;
        if(N == 1) return 1;
        vector<int> a(N + 1);
        a[0] = 0;
        a[1] = 1;
        int i = 2;
        while(i <= N)
            a[i++] = a[i - 1] + a[i - 2];
        return a[N];
    }
};
