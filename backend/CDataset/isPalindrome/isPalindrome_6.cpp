	class Solution {
	public:
		bool isPalindrome(int x) {
			int revNo=0;
			int n=x;
			int rem;
			if(x<0) return false;
			if(x%10==x) return true;
			while(n!=0)
			{
				rem=n%10;
				n/=10;
				if (revNo > INT_MAX/10 || (revNo == INT_MAX / 10 && rem > 7)) return 0;
				if (revNo < INT_MIN/10 || (revNo == INT_MIN / 10 && rem < -8)) return 0;

				revNo=revNo*10 + rem;
			}
			return (revNo==x) ? true : false;
		}
	};
