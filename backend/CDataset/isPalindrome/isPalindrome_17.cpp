class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x); //convert int x to a string
        string s2 = s; //make a copy of the string representation of int x to reverse
        reverse(s2.begin(), s2.end()); //use reverse to reverse s2  from its beginning to end
        return (s == s2); //*see note below
    }
};