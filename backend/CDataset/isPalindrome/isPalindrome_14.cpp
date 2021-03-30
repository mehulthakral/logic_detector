class Solution {
public:
    bool isPalindrome(int x) {
        
        string str=to_string(x);
        string s=str;
        reverse(str.begin(),str.end());
        
        if(str == s)    return true;
        return false;
    }
};
