int strStr(string haystack, string needle) {
        int sz_haystack = haystack.size();
    	int sz_needle = needle.size();
    	for (int i = 0; i+sz_needle-1 < sz_haystack;)
    	{
    		if (needle == haystack.substr(i, sz_needle))
    			return i;
    		else
    		{
    		    int step = sz_needle;
    			for (int j = 0; j <= sz_needle-2; j++)
    			{
    			    if (haystack[i+sz_needle-1] == needle[j])
    			        step = sz_needle-1-j;
    			}
    			i = i+step;
    		}
    	}
    	return -1;
    }
