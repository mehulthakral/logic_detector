class Solution {
public:
    int mySqrt(int x) {
        if(x==0) return 0;
        if(x<4) return 1;
        int ans;
        for(long long int i=2; i<=x/2+1; i++) {
            if(i*i==x || i+1<=x/2+1 && (i*i<x && (i+1)*(i+1)>x)) {
                ans= i;
                break;
            }
        }
        return ans;
    }
};