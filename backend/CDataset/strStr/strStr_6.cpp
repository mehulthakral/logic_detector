class Solution {
public:
    void computelps(string pattern,int n,vector<int>&lps) {
        int i=1;
        int len =0 ;
        lps[0]=0;
        while(i<n) {
            if(pattern[i] == pattern[len]) {
                len++;
                lps[i] =len;
                i++;
            }
            else  {
                if(len!=0) {
                    len = lps[len-1];
                }
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
    
    
    int strStr(string word, string pattern) {
        int m = word.length();
        int n = pattern.length();
        if(n==0) return 0;
        if(m==0 && n==0)
            return 0;
        if(n>m) return -1;
        vector<int> lps(n);
        computelps(pattern , n, lps);
        int i=0 ,j =0;
        while(i<m) {
            if(pattern[j] == word[i]) {
                i++;
                j++;
            }
            if(j==n) 
                return i-j;
            if(i<m && pattern[j]!=word[i]) {
                if(j!=0)
                    j = lps[j-1];
                else
                    i++;
            }
        }
        return -1;
    }
};
