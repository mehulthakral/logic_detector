class Solution {
public:
    Solution(){
        f[0] = 0;
        f[1] = 1;
        for(int i=2; i<31; ++i) f[i] = f[i-1] + f[i-2];
    }
    int fib(int N) {
        return f[N];
    }
private:
    int f[31];
};
