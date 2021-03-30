class Solution {
public:
    int strStr(std::string haystack, std::string needle) {

        if(needle.empty()) return 0;
        size_t i;
        for(i = 0; i < haystack.size(); ++i) {
            if(haystack[i] != needle[0]) {
                continue;
            }
            for(size_t index = 0, j = i; j < haystack.size() && haystack.at(j) == needle.at(index);++j) {
                if(++index == needle.size()) {
                    return i;
                } 
            }
        }
        return -1;
    }

};
