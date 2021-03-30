double myPow(double x, int n)
{
	unsigned int m = (n > 0)?n:-n;

	for(double res = double(1);; x *= x)
	{
		if((m & 1) != 0)
		{
			res *= x;
		}
		if((m >>= 1) == 0)
		{
			return (n < 0?double(1) / res:res);
		}
	}

}
