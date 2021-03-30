class Solution {
public:
    int fib(int N) {
        int cur = 0;
        int pre = 1;
        int i = 0;
        while(i++<N){
            cur = cur + pre;
            pre = cur - pre;
        }
        return cur;
    }
};
