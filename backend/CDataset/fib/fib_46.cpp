class Solution {
public:
int countways(int N, int* memo)
{
if(N<0) return 0;
else if(N==0) return 0;
else if(N==1) return 1;
else if(memo[N]>-1) return memo[N];
else memo[N] = (countways((N-1), memo)+countways((N-2), memo));
return (memo[N]);
}

int fib(int N) 
{           
    int memo[N+1];
    for(int i=0; i<N+1; i++)
        memo[i] = -1;
    return (countways(N, memo));
}
};