class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle=="") return 0;
        int len1 = haystack.length(), len2 = needle.length();
        if(len1<len2) return -1;
        map<char, int> mapping;
        for(int i = 0;i<needle.size();++i)
            mapping[needle[i]] = i;

        int i = 0;
        while(i<=len1-len2){
            int j = 0;
            for(;j<len2;++j){
                if(haystack[i+j] != needle[j]){
                    char c = haystack[i+len2];
                    if(mapping.find(c)==mapping.end()) i += len2+1;
                    else i += len2-mapping[c];
                    break;
                }
            }
            if(j == len2) return i;
        }
        return -1;
    }
};