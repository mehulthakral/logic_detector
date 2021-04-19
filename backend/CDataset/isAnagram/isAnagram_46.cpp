class Solution {
public:
bool isAnagram(string s, string t) {
        multiset<char> msc1(s.begin(), s.end());
        multiset<char> msc2(t.begin(), t.end());
        return msc1==msc2;
}
};