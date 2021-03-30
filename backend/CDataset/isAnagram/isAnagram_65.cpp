class Solution
{
public:

bool isAnagram(std::string s, std::string t) 
{
    std::unordered_map<char, int> ma;
    std::unordered_map<char, int> mb;
    
    for(const auto &el: s)
    {
        ma[el]++;
    }
    
    for(const auto &el: t)
    {
        mb[el]++;
    }
    
    return ma == mb; 
}
};