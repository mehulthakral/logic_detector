class Solution
{
public:
	   double pow(double x, int n)
	{
		if (n == 0)
		{
			return 1;
		}
		if (n % 2 == 1)
		{
			return x * pow(x * x, n / 2);
		}
		return pow(x * x, n / 2); 
		// 2^4 = 2^2 * 2^2 == 4^2 this logic is used here. so using the recursion it the stack will reach upto eight of logn only.
	}
	double pow2(double x, int n)
	{
		if (n == 0)
		{
			return 1;
		}
		if (n % 2 == -1)
		{
			return pow2(x * x, n / 2) / x;
		}
		return pow2(x * x, n / 2);
	}
	double myPow(double x, int n)
	{
		if (n == 0)
		{
			return 1.00000;
		}

		ios::sync_with_stdio(0);
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
		cout << fixed;
		cout << setprecision(5);

		double res;

		if (n > 0)
		{
			res = pow(x, n);
		}
		else
		{
			res = pow2(x, n);
		}

		return res;
	}
};
