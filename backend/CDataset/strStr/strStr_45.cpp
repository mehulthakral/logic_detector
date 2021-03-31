int strStr(string haystack, string needle) {
    if(haystack.size() == 0 && needle.size() == 0) return 0;
    int pos = 0, diff = static_cast<int>(haystack.size()-needle.size());
    for(;pos <= diff;pos++){
        int j = 0;
        for(; j < needle.size(); j++)
            if(haystack[pos+j]!=needle[j]) break;
        if(j == needle.size()) return pos;
    }
    return -1;
}