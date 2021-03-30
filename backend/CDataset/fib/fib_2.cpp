class Solution {
public:
    int fib(int n) {
        if (n==0) return 0;
        if(n<2) return 1;
        long a=0,b=1,c=0;
        for(int i=2;i<=n;i++){
            c=a+b;
            a=b;
            b=c;
        }
        return c;
    }
};
