class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty())
            return 0;
        
        string kmp = needle + "#" + haystack;
        
        int m = kmp.size(), n = needle.size();
        
        vector<int> lps(m , 0);
        
        for(int i = 1, len = 0; i < m;){
            if(kmp[i] == kmp[len]){
                lps[i] = ++len;
                if(len == n)
                    return i - 2 * n;
                ++i;
            }
            else if(len == 0)
                lps[i++] = 0;
            else
                len = lps[len - 1];
        }
        return -1;
    }
};
