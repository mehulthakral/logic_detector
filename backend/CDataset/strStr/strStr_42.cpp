class Solution {
public:
    int strStr(string haystack, string needle) {
    
        if(needle.size() > haystack.size())
    		return -1;
    
    	if(needle.size() < 1)
    		return 0;
    
    	int hsize = haystack.size();
    	int nsize = needle.size();
    	bool isNeedle;
    	
    	for(int i = 0; i <= hsize - nsize; i++)
    	{
    		if(haystack[i] == needle[0])
    		{
    			isNeedle = true;
    
    			for(int j =1; j < nsize; j++)
    			{
    				if(haystack[i+j] != needle[j])
    				{
    					isNeedle = false;
    					break;
    				}
    			}
    
    			if(isNeedle)
    				return i;
    		}
    	}
    
    	return -1; 
    
    }
};