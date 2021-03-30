class Solution {
public:
    int fib(int N) {
        int a = 0, b = 1, c;
        if (N < 2) return N;
        
        for (int i=2; i<=N; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};
