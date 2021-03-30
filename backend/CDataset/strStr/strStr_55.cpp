class Solution
{
public:

int strStr(std::string haystack, std::string needle) 
{     
    const auto dim1 = haystack.size();
    const auto dim2 = needle.size();
    
    int pos = 0;
    
    while(true)
    {
        const auto tmp = haystack.substr(pos, dim2);
        
        if(tmp == needle) return pos;
        
        pos++;
        
        if(pos + dim2 > dim1) break;
    }
          
    return -1;
}
};