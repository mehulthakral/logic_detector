class Solution {
public:
    int fib(int N) {
        if (N <= 1)
            return N;
        int a = 0;
        int b = 1;
        for (int j = 2; j < N; j++) {
            int c = a + b;
            a = b;
            b = c;
        }
        return a + b;
    }
};
