class Solution {
public:
    bool isAnagram(string s, string t) {
        array<int, 'z' - 'a' + 1> occ_s{ 0 };
        array<int, 'z' - 'a' + 1> occ_t{ 0 };
        for (auto& c : s) occ_s[c - 'a']++;
        for (auto& c : t) occ_t[c - 'a']++;
        
        return equal(occ_s.begin(), occ_s.end(), occ_t.begin());
    }
};
