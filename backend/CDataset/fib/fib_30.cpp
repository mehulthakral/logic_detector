class Solution {
public:
    int fib(int N)
    {
        int prev[] = { 0, 1 }; 
        int p = 0; 
        if (N <= 1) {
            return N;
        } else {
            for (int i = 2; i <= N; i++) {
                prev[p] = prev[0] + prev[1];
                p = (p + 1) % 2;
            }
            return prev[(p + 1) % 2];
        }
    }
};