class Solution {
public:
	int countPrimes(int n) {
		if(n==0 ||n==1)return 0;

		bool prime[n+1];

		for(int i=2;i<n;i++){
			prime[i]=true;
		}

		for(int p=2; p*p<n; p++){

			if(prime[p]==true){

				for(int j=p*p;j<n;j+=p)
					prime[j]=false;

			}
		}

		int ans = 0;

		for(int i=2;i<n;i++){
			if(prime[i]==true)ans++;
		}

		return ans;

	}
};
