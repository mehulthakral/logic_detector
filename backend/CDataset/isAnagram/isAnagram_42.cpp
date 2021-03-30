class Solution {
public:
    bool isAnagram(string s, string t) {
        int a[26]={0} ;
        for(int i=0;i<s.length();i++)
        {
            a[s[i]-'a']++;
        }
        for(int i=0;i<t.length();i++)
        {
            a[t[i]-'a']--; 
        }
        for(int i=0;i<26;i++)
            if(a[i]) return 0;
        return 1;
    }
};
