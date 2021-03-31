class Solution 
{
public:
	int strStr(string haystack, string needle)
	{
		int len = haystack.size() - needle.size() + 1;
		for (int i = 0; i < len; ++i)
		{
			if (haystack.substr(i, needle.size()) == needle) return i;
		}
		return -1;
	}
};