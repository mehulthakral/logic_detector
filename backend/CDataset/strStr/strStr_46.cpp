class Solution {
public:
    int strStr(char *haystack, char *needle) {
        string a(haystack);
        return a.find(needle)==a.npos?-1:a.find(needle);
    }
};
