class Solution {
public:
    int fib(int N) 
    {
        int n1 = 0;
        int n2 = 1;
        int answer = 0;
        if(N == 0) return 0;
        if(N == 1) return 1;
        
        for(int i = 2 ; i <= N; i++)
        {
            answer = n1+n2;
            n1 = n2;
            n2 = answer;
        }
        return answer;
    }
};
