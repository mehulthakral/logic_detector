class Solution {
public:
int strStr(string haystack, string needle) {
        
        if(needle.length()==0)
            return 0;
        if(haystack.length()==0)
            return -1;
        
        int i=0,j=0,start;
        
        while(i<haystack.length() && j<needle.length())
        {
            if(j==0)
                start=i;
                    
            if(haystack[i]==needle[j])
            {
                i++;
                j++;
                if(j==needle.length())
                    return i-j;
                continue;
            }
            
            j=0;
            i=start+1;
        }
        
        return -1;
    }
};