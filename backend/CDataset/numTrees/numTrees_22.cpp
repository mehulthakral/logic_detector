class Solution {
public:
int numTrees(int n) {
long long int dp[n+1];
memset(dp,0,sizeof(dp));
dp[0]=1;
for(int i=1;i<=2*n;i++){
for(int j=min(i,n);j>0;j--){
dp[j]=dp[j-1]+dp[j];
}
}
return dp[n]/(n+1);
}
};