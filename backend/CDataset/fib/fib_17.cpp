class Solution {
public:
    int fib(int N) {
        int f=0, a=0, b=1;
        if(N==0)    return 0;
        if(N==1)    return 1;
        for(int i=0; i<N; i++)
        {
            f=a+b;
            a=b;
            b=f;
        }
        return a;
    }
};
