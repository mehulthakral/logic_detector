class Solution {
public:
int strStr(string haystack, string needle) {
        if(strstr(haystack.c_str(),needle.c_str()))
        {
            size_t found;
            found=haystack.find(needle);
            if (found != string::npos) return found; 
            return 0;
        }
        return -1;
    }
};