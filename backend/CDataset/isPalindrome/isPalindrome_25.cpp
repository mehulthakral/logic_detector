class Solution {
public:
    bool isPalindrome(int x) {

        if(x < 0){
            return false;
        }
        
        string y = to_string(x);
        
        reverse(y.begin(), y.end());
        
        return y == to_string(x);
    }
};