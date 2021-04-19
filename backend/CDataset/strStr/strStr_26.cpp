class Solution
{
public:
	int strStr(string haystack, string needle)
	{
		int len = haystack.size() - needle.size() + 1;
		for (int i = 0; i < len; ++i)
		{
			int j = 0;
			while (j < needle.size()) 
			{
				if (haystack[i + j] != needle[j]) break;
				else ++j;
			}
			if (j == needle.size()) return i;
		}
		return -1;
	}
};