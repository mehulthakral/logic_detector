class Solution {
public:
    int reverse(int x) {
        if(x==0)return 0;
        long long int n=x;
        if(n<0)n=-n;
        long long int ans=0;
        while(n>0){
            ans=ans*10+n%10;
            n=n/10;
            if(ans>pow(2,31)-1)return 0;
        }
        if(x<0)return -ans;
        return ans;
    }
};