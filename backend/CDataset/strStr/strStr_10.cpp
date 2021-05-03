class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        string s = needle + "$" + haystack;
        int n = s.length();
        vector<int> ps(n, 0);
        for(int i = 1; i < n; i++) {
            int j = ps[i-1];
            while(j > 0 && s[i] != s[j])
                j = ps[j-1];
            if(s[i] == s[j])
                j++;
            ps[i] = j;
            if(j == needle.length()) return i-2*needle.length();
        }
        return -1;
    }
};
