class Solution {
public:
	bool isPalindrome(int x) {
		if(x<0) return false;
		int a=abs(x);
		long int num=0;
		while(a!=0){
			int cur=a%10;
			num=num*10+cur;
			a/=10;         
		}
		if(num==x) return true;
		else return false;   
	}
};