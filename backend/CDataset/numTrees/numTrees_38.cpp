int numTrees(int n)
    {
    	if (n <= 0)
    		return 0;
    
    	map<int, int> dic;
    	dic[0] = 1;
    	for (int i = 1; i <= n; i++)
    	{
    		for (int j = 1; j <= i; ++j)
    		{
    			dic[i] += dic[j - 1] * dic[i - j];
    		}
    	}
    	return dic[n];
    }