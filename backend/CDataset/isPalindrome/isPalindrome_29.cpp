class Solution
{
public:

bool isPalindrome(int x) 
{
    if(x < 0) return false;
    
    std::string s1 = std::to_string(x);
    std::string s2 = s1;
    std::reverse(s2.begin(), s2.end());
    
    if(s1 == s2) return true;
    
    return false;
}
};