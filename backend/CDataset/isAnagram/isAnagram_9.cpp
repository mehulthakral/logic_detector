class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> ump;
        for(int i=0;i<s.size();i++){
            ump[s[i]]++;
        }
        
        for(int i=0;i<t.size();i++){
            if(ump.find(t[i])!=ump.end()){
                ump[t[i]]--;
                if(ump[t[i]]==0) ump.erase(t[i]);
            }else{
                return false;
            }
        }
        
        if(ump.size()==0) return true;
        else return false;
    }
};
