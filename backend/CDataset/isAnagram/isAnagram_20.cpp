class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() == 0 && t.size() == 0) return true;
        if(s.size() == 0 || t.size() == 0) return false;
        if(s.size() != t.size()) return false;
        int sa[26] = {0};
        int ta[26] = {0};
        for(int i=0;i < s.size();i++){
            sa[s[i] - 'a']++;
            ta[t[i] - 'a']++;
        }
        for(int i=0;i<26;i++)
            if(sa[i] != ta[i]) return false;
    return true;
    }
};
