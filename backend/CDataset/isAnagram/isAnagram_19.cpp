class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        return std::is_permutation(std::cbegin(s), std::cend(s), std::cbegin(t), std::cend(t));
    }
};
