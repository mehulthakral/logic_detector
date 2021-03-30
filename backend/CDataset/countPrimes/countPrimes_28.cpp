class Solution {
public:
	int countPrimes(int n) {
		int ans=0;
		vector<int> dp(n,1);
		for(int i=2;i<n;i++){
			if(dp[i]==1){
				ans++;
				int cur=i;
				int tem=2;
				while(cur*tem<n){
					dp[cur*tem]=0;
					tem++;
				}
			}
		}
		return ans;   
	}
};