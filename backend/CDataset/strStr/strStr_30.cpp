class Solution {
public:
    // KMP match algorithm
    int strStr(string haystack, string needle) {
        if(needle=="") return 0;
        int len1 = haystack.size(), len2 = needle.size();
        if(len1<len2) return -1;
        
        vector<int> lps(needle.size());
        computeLPSArray(needle, lps);
        int i = 0 , j = 0;
        while(i<len1 && j<len2){
            if(haystack[i] == needle[j]){
                ++i;
                ++j;
            }else if(j) j = lps[j-1];
            else ++i;
        }
        if(j == len2) return i-j;
        return -1;
    }
    //calculate string needle's lps (longest prefix and suffix length) array
    void computeLPSArray(string & needle, vector<int> & lps){
        if(lps.size()!=needle.size()) return;
        lps[0] = 0;
        int len = 0, i = 1;
        while(i<needle.size()){
            if(needle[len] == needle[i]) lps[i++] = ++len;
            else if(len) len = lps[len-1];
            else lps[i++] = 0;
        }
    }
};