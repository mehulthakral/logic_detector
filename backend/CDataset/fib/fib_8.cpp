class Solution {
public:

Solution() {

    res[0] = 0;
    res[1] = 1;
         
    int xNm2 = 0;
    int xNm1 = 1;
    int xN = 0;
    
    for(int i = 2; i <= 30; i++)
    {
        xN = xNm1 + xNm2;
        xNm2 = xNm1;
        xNm1 = xN;
        
        res[i] = xN;
    }
}

int fib(int N) {
    return res[N];
}

static int res[31];
};

int Solution::res[31];