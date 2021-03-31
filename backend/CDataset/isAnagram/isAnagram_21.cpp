class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        if(s.empty() && t.empty())
            return true;
        if((s.empty() && !t.empty()) || (!s.empty() && t.empty()))
            return false;
        
        int n= t.size(), m= s.size(), sum=0;
        
        if(n!=m)
            return false;
                
        vector<int>v(26,0);
        
        for(int i=0; i<n; i++) {
             v[t[i]-97]++;
        }
        for(int i=0; i<m; i++) {
             v[s[i]-97]--;
        }
        
        for(int i=0; i<26; i++) {
             if(v[i] != 0)
                 return false;
        }
        
        return true;
    }
};