class Solution {
public:
int strStr(string haystack, string needle) {
    for (int i = 0; i < (int)(haystack.size()-needle.size()+1); i++) {
        int j = 0;
        while (j < needle.size() && haystack[i+j] == needle[j])
            j++;
        if (j == needle.size()) 
            return i;
    }
    return -1;
}
};