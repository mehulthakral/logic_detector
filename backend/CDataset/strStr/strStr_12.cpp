class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle == "") return 0;
        int subSize = needle.length(), haySize = haystack.length();
        for(int i=0; i<=haySize-subSize; i++) {
            string sub = haystack.substr(i, subSize);
            if(sub == needle)
                return i;
        }
        return -1;
    }
};