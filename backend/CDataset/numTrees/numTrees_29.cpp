class Solution {
public:
    int numTrees(int n) {
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        long long ans=0;
        ans=ceil(exp(lgamma(2*n+1)-lgamma(n+1)-lgamma(n+1)));
        cout<<ans<<endl;
        return (ans)/(n+1);
    }
};