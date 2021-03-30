static auto x = []() {ios_base::sync_with_stdio(false); cin.tie(NULL); return NULL; }();

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) { return 0; }
        else if(needle.size()>haystack.size()){ return -1; }
        
        for(short int i=0; i<(haystack.size()-needle.size()+1); ++i){
            for(short int j=0;j<needle.size(); ++j){
                if (haystack[i+j]!=needle[j]) { break; }
                else if (j+1==needle.size()) { return i; }
            }
        }
        return -1;
    }   
};
