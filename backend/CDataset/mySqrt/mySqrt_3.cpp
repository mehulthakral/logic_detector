class Solution {
public:
    int mySqrt(int x) {
        double n;
        int ans;
        if(x==0 || x==1){
            return x;
        } 
        n = sqrt(x);
        cout<<n;
        ans = floor(n);
        return ans;
    }
};
