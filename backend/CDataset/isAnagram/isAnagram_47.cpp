class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> c1(26, 0), c2(26, 0); // for storing character counts of 's' and 't' respectively
        
        // keep character count in s
        for (char c: s) c1[c-'a'] ++;
        
        // keep character count in t
        for (char c: t) c2[c-'a'] ++;
        
        // check the character count of each characters, if any one is not equal then return false
        for (int i = 0; i < 26; ++i) {
            if (c1[i] != c2[i]) 
                return false;
        }
        return true;
    }
};