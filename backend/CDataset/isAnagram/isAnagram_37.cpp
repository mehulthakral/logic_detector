class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        string alph = "abcdefghijklmnopqrstuvwxyz";
        int sum = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s.find(t[i]) == string::npos) {
                return false;
            }
            sum += alph.find(s[i]) - alph.find(t[i]);
        }
        if (sum != 0) {
            return false;
        } else {
            return true;
        }
    }
};
