class Solution
{
	public:
	bool isPalindrome(int x)
	{
		if(x < 0)  return false;
		if(x == 0) return true;
		int digits = 0;
		int tem = x;
		digits = int(log10(x));
		tem = x;
		while((digits > 0) &&
			  (tem % 10) == (tem / int(pow(10, digits))))
		{
			tem -= tem % 10 + (tem % 10)*int(pow(10, digits));
			tem /= 10;
			digits -= 2;

		}
		return (digits <= 0)?true:false;
	}
};
