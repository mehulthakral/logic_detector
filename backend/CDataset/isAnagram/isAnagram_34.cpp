class Solution {
public:
    bool isAnagram(string s, string t) {
		// quick exit condition
        if (s.size() != t.size()) return false;
		// working with frequencies now
        int alpha[26] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        for (char c: s) alpha[c - 'a']++;
        for (char c: t) alpha[c - 'a']--;
        return all_of(begin(alpha), end(alpha), [](int a){return a == 0;});
    }
};
