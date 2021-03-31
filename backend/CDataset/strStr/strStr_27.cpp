class Solution {
public:
    //use kmp
    vector<int> f;
   // it should be needle. sorry for carelessness. pass needle to it.
    void failure(string& haystack){
        for(int i = 1, j = -1;i < haystack.length(); ++i){
            while(j >= 0 && haystack[j + 1] != haystack[i]){
                j = f[j];
            }
            if(haystack[j + 1] == haystack[i]){
                ++j;
            }
            f[i] = j;
        }
    }
    int search(string& haystack, string& needle){
        for(int i = 0, j = -1;i < haystack.length(); ++i){
            while(j >= 0 && needle[j + 1] != haystack[i]){
                j = f[j];
            }
            if(needle[j + 1] == haystack[i]){
                ++j;
            }
            if(j == needle.length() - 1){
                return i - needle.length() + 1;
            }
        }
        return -1;
    }
    int strStr(string haystack, string needle) {
        if(haystack.length() < needle.length()){
            return -1;
        }else if(needle == ""){
            return 0;
        }
        f = vector<int>(haystack.length(), -1);
        failure(needle);
        return search(haystack, needle);
    }
};