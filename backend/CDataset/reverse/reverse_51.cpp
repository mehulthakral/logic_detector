int reverse(int x) {
	int ch[40] = {};
	int i = 0;
	int flag = 1;
	if (x < 0)
	{
		flag = -1;
		x = abs(x);
		
	}

	while (x>0)
	{
		ch[i++] = x % 10;
		x=x / 10;
	}
	int length = i;


	int reverse = 0;
	for (size_t i = 0; i < length; i++)
	{
		if (ch[i]!=0)
		{
			reverse += ch[i]*pow(10, length - i-1);
			if (reverse < 0)
			{
				return 0;
			}
		}
	}

	return reverse*flag;
}