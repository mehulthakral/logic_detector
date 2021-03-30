class Solution {
public:
    static bool isAnagram(const std::string& s, const std::string& t) {
        if (s.length() != t.length()) {
            return false;
        } else {
            std::array<int, 26> a {};  // empty initialization list means all zero
            for (char c : s) a[c - 'a']++;
            for (char c : t) a[c - 'a']--;
            return std::all_of(a.cbegin(), a.cend(), std::logical_not{});  // all elements in the array should be zero
        }
    }
};
