class Solution {
public:
    int mySqrt(int x) {
        if(x==1) return 1;
        int l=0, r=x/2;
        while(l<r) {
            long m=l+(r-l)/2;
            if(m*m==x||m*m<x&&(m+1)*(m+1)>x)
                return m;
            if(m*m>x)
                r=m-1;
            if(m*m<x)
                l=m+1;
        }
        return l;
    }
};
