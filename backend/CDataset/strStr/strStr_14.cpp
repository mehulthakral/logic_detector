class Solution {
public:
    int strStr(string haystack, string needle) {
        if (empty(needle)) return 0;

        for (int i = 0; i < haystack.size(); ++i) {
            if (haystack.size() - i < needle.size()) return -1;
            if (haystack.substr(i, needle.size()) == needle) return i;
        }
        
        return -1;
    }
};
