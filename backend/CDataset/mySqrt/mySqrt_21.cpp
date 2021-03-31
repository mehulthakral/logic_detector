class Solution {
public:
    int mySqrt(int x) {
        if(x==1){
            return 1;
        }
        int l=0;
        int r=x;
        while(l<=r){
            //cout<<l<<" "<<r<<endl;
            int mid=(l+r)/2;
            if(((long long)mid*(long long)mid)>=INT_MAX){
                r=mid;
                continue;
            }
            if(mid*mid==x){
                return  mid;
            }else if(mid*mid>x){
                r=mid;
            }else{
                l=mid;
            }
            if(r==l+1){
                return l;
            }
        }
        
        return x;
    }
};
