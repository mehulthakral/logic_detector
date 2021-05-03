class Solution {
public:
void kmp(string haystack, string needle, vector<int> &psl, int &pos, bool build = true) {
    int hl = haystack.length(), nl = needle.length();
    if (nl == 0) {
        pos = 0;
        return;
    } 
    if (build) psl.resize(hl);
    for (int i = 0, j = build ? 1 : 0; j < hl; j++) {
        if (needle[i] == haystack[j]) {
            i++;
        } else if (i > 0) {
            i = psl[i - 1];
            j--;
            continue;
        }
        if (build) psl[j] = i;
        else if (i ==  nl) {
            pos = j - nl + 1;
            return;
        }
    }
    
}
int strStr(string haystack, string needle) {
    vector<int> psl;
    int pos = -1;
    kmp(needle, needle, psl, pos);
    kmp(haystack, needle, psl, pos, false);
    return pos;
}
};