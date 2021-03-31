bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        vector<int>c1(26,0);
        for(int i=0;i<s.size();i++) c1[s[i]-'a']++,c1[t[i]-'a']--;
        for(int i=0;i<26;i++) if(c1[i]) return false;
        return true;
    }
