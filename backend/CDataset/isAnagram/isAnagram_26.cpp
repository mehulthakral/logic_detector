class Solution {
public:
    bool isAnagram(string s, string t) {
     std::vector<char> map(128,0);
    std::vector<char> _map(128,0);
    
    for(auto x : s)
    {
        map[x]++;
    }
    
    for(auto z : t)
    {
        _map[z]++;
    }
    
    return map == _map;  
    }
};