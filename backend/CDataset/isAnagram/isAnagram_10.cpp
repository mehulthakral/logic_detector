class Solution {
public:
    bool isAnagram(const string& s, const string& t) {
        return unordered_multiset(s.begin(), s.end()) == unordered_multiset(t.begin(), t.end());
    }
};
