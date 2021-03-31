int fib(int N) {
        if(N==0)
            return 0;
        if(N==1)
            return 1;
        int a=0,b=1,ans;
        for(int i=2;i<=N;i++)
        {  
            ans = a + b;
            a=b;
            b=ans;
        }
        return ans;
    }
