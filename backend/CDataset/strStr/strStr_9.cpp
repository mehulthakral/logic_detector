class Solution {

public:
    int strStr(string haystack, string needle) 
    {
        int hay_len = haystack.length();
        int need_len = needle.length();
        int match_len = hay_len-need_len;
        
        if( need_len == 0 )
            return 0;
        
        for(int i=0 ;i <= match_len ; i++)
        {   
               int j=i, k = 0;
               while( k < need_len && haystack[j] == needle[k]) 
               {
                  k++;j++;
               }
               if( k == need_len)
                  return i;
        }
        return -1;
    }
};
