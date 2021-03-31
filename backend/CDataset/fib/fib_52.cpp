class Solution {
public:

int fib(int N) {
    
    if(N == 0) return 0;
    if(N == 1) return 1;
    
    if(res[N-1] == 0)
    {
        res[N-1] = fib(N-1);
    }
    
    if(res[N-2] == 0)
    {
        res[N-2] = fib(N-2);
    }
    
    return res[N-1] + res[N-2]; 
}
private:

static std::vector<int> res;
};

std::vector Solution::res = std::vector(30, 0);