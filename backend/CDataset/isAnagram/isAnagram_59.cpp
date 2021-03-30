class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> mps;
        map<char, int> mpt;
        for(auto i : s){
            mps[i]++;
        }
        for(auto i : t){
            mpt[i]++;
        }
        return mps == mpt;
    }
};