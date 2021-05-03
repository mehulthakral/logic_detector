
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(!needle.length())return 0;
        size_t ind=haystack.find(needle);
        return (ind==string::npos)?-1:ind;
    }
};
