class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map <char,int> map_s,map_t;
        if (s.size() != t.size()){
            return false;
        }
        for (int i = 0; i < s.size(); i++){
            char s1 = s[i], t1 = t[i];
            if (map_s.find(s1) == map_s.end()){
                map_s[s1] = 1;
            }else{
                map_s[s1]++;
            }
            if (map_t.find(t1) == map_t.end()){
                map_t[t1] = 1;
            }else{
                map_t[t1]++;
            }
        }
        return map_s == map_t;
    }
};
