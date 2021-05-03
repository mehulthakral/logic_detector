class Solution {
public:
    int fib(int n) {
        if(n<2)return n;
        int x=0,y=1,res=0;
        for(int i=1;i<n;i++){
            res=x+y;
            x=y;
            y=res;
        }
        return res;
    }
};
