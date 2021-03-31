class Solution {
public:
	int countPrimes(int n) {
		if(n==0) return 0;   
		vector<bool> dp(n,true);
		dp[0]=false;
		dp[1]=false;
		for(int i=0;i<=sqrt(n);i++){
			if(dp[i]){
				for(int j=2;i*j<=n;j++){
					dp[i*j]=false;
				}
			}
		}
		return count(dp.begin(),dp.end(),true);


	}
};