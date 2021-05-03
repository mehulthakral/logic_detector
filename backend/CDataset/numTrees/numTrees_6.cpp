class Solution {
public:
	int numTrees(int n) {
		double ans=1, i=2*n;
		//using formula directly i.e for value=n, number of trees possible= ((2n)C(n))/(n+1)
		//calculating numerator (2n)C(n) that is equal to ((2n)*(2n-1)*...n terms) / (n*(n-1)*...*1)

		for(int j=1; j<=n; i--,j++){ // i goes from 2n to n terms and j goes from 1 to n
			ans*= i/j;
		}

		return ans/(n+1);
	}
};