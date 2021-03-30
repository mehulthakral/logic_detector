class Solution {
public:
    int strStr_(string s, string p) {
        if(s == p || p.empty()) return 0;
        if(s.size() < p.size()) return -1;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == p[0]){
                if(s.substr(i, p.size()) == p){
                    return i;
                }
            }
        }
        return -1;
    }
    
    int strStr(std::string s1, std::string s2) {
        // using rolling hash
        if(s1 == s2 || s2.empty()) return 0;
        if(s1.size() < s2.size()) return -1;

        int p = 10001; //1000000007; 
        int b = 7;//257;

        int64_t hash1 = 0;
        int64_t hash2 = 0;
        int64_t power = 1;
        for(int i = 0; i < s2.size(); i++){
            hash2 = (hash2 * b + s2[i]) % p;
            power = (power * b) % p;
        }

        int index = -1;
        for(int i = 0; i < s1.size(); i++){
            hash1 = (hash1 * b + s1[i]) % p;

            if( i >= s2.size()){
                hash1 -= power * s1[i - s2.size()] % p;
                if( hash1 < 0){
                    hash1 += p;
                }
            }
            if( i >= s2.size() - 1 && hash1 == hash2){
                index = i - (s2.size() - 1);
                break;
            }
        }
        return index;
    }
};
