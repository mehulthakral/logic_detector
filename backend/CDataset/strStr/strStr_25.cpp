class Solution {
public:
        
    int strStr(string haystack, string needle) {
        const char* a=haystack.c_str(), *b=needle.c_str();
        const char* c=strstr(a, b);
        if(c==NULL) return -1;
        return c-a;
    }
};
