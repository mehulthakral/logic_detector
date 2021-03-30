class Solution {
public:
    bool isAnagram(string s, string t) {
        // edge case: different lengths
        if (s.size() != t.size()) return false;
        // support variables
        int freqs[128] = {};
        // adding frequencies of s
        for (char c: s) freqs[c]++;
        // removing frequencies of t
        for (char c: t) freqs[c]--;
        // veryfying no character is mismatched
        for (int i = 97; i < 123; i++) if (freqs[i]) return false;
        return true;
    }
};
