class Solution {
public:
    bool isAnagram(string s, string t) {
        
         if (s.length() != t.length()) {
        return false;
    }
        if(s.size() == 0 and t.size()==0) return true;
        
        unordered_map<char,int> map;
        int matched = 0;
        for(auto x : t)
        {
            map[x]++;
        }
        
        for(int end =0 ; end<s.size(); end++){
            char right = s[end];
            if(map.find(right)!=map.end()){
                map[right]--;
                if(map[right] == 0){
                    matched++;
                }
                if(matched == map.size())
                    return true;
                
                
            }
            
        }
        return false;
    }
};
