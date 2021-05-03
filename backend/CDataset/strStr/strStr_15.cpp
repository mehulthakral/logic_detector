class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.length();
        int m=needle.length();
        if(m==0)
            return 0;
        int j;
        vector<int> dp(m,0);
        j=0;
        for(int i=1;i<m;i++)
        {
            while(j>0 && needle[j]!=needle[i])
            {
                j=dp[j-1];
            }
            if(needle[i]==needle[j])
                j++;
            dp[i]=j;       
        }
        j=0;
        for(int i=0;i<n;i++)
        {
            while(j>0 && needle[j]!=haystack[i])
                j=dp[j-1];
            if(needle[j]==haystack[i])
                j++;
            if(j==m)
                return i-j+1;           
        }
        return -1;
        
    }
};

