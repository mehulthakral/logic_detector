class Solution {
public:
bool isAnagram(string s, string t) {
        if(s.size() == 0 && t.size() == 0) return true;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if(s==t) return true;
        else return false;
        
    }
};