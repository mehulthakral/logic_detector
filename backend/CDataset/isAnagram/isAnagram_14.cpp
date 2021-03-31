class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> S, T;
        for (char c : s) {
            S[c]++;
        }
        for (char c : t) {
            T[c]++;
        }
        return S == T;
    }
};
