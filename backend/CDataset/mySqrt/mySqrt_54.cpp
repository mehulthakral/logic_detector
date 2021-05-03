class Solution {
public:
	int mySqrt(int x) {
		long long high=x;
		long long low=0;
		long long mid=(high-low)/2+low;
		while(low+1<high){
			mid=(high-low)/2+low;
			if(mid*mid==x) return mid;
			if(mid*mid>x){
				high=mid;
			}
			else{
				low=mid;
			}
		}
		if(high*high<=x) return high;
		if(mid*mid<=x) return mid;

		return low;

	}
};