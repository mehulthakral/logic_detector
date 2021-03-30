class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        // STL solution using std::search and
        // std::boyer_moore_horspool_searcher
        // where M = length of haystack,
        // N = length of needle
        // time = O(N) in the average case
        // O(NM) in the worst case
        if (needle.empty()) return 0;
        if (haystack.empty()) return -1;
        if (needle.length() > haystack.length()) return -1;
        
        auto it = std::search(haystack.begin(), haystack.end(),
                        std::boyer_moore_horspool_searcher(needle.begin(),
                                            needle.end()));
        
        if (it != haystack.end()) return it - haystack.begin();
        else return -1;
    }
};
