class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.length() <= 0) return 0;
        for (unsigned int i=0; i<haystack.length(); i++){
            if (haystack[i] == needle[0]){
                bool match = 1;
                if (i+needle.length()-1 <= haystack.length()-1){
                    for (unsigned int j=1; j<needle.length(); j++){
                        if (haystack[i+j] != needle[j]) match=0;
                    }if (match) return i;
                }else return -1;
            }
        }return -1;
    }
};
