class Solution
{
public:

int strStr(std::string haystack, std::string needle) 
{      
    const auto pos = haystack.find(needle);
    
    if (pos != std::string::npos)
    {
        return pos;
    }
    
    return -1;
}
};