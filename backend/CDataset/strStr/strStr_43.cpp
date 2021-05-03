class Solution {
public:
    int strStr(string haystack, string needle) {
        int lenh = haystack.length();
        int lenn = needle.length();
        bool flag = true;
        if(needle == "") return 0;
        for(int i = 0; i < lenh - lenn + 1; i++) {
            if(haystack[i] == needle[0]) {
                for(int j = 0; j < lenn; j++) {
                    if(haystack[j + i] != needle[j]) {
                        flag = false;
                        break;
                    } else flag = true;
                }
                if(flag) return i;
            }
        }
        return -1;
    }
};