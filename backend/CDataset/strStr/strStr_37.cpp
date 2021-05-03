class Solution {
public:
    int strStr(string haystack, string needle) {
        if (!needle.size()) return 0;
        string combo = needle + '#' + haystack;
        vector<int> z(combo.size());
        int high = 0, it = 0;
        for (int i = 1; i < combo.size(); ++i) {
            high = max(high, i);
            if (high > i && z[i - it] + i != high) {
                z[i] = min(z[i - it], high - i);
            } else {
                it = i;
                while(high < combo.size() && combo[high] == combo[high - i]) {
                    high++;
                }
                z[i] = high - i;
                if (z[i] == needle.size()) {
                    return i - needle.size() - 1;
                }
            }
        }
        return -1;
        
    }
};
