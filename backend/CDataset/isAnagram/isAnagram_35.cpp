class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> hash;
        for(char i:s) hash[i]++;
        for(char i:t) 
            if(--hash[i] == 0) hash.erase(i);
        return hash.empty();
    }
};
