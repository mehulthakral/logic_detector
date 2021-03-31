class Solution {
public:
    int mySqrt(int x) {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        long long int l=0,r=x,m;
        while(l<=r) {
            m = l + (r-l)/2;
            if(m*m >= x) {
                r = m-1;
            }
            else {
                if((m+1)*(m+1) > x ) {
                    return m;
                }
                l = m+1;
            }
        }
        return l;
    }
};
