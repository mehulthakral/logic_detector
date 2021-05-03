class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        
        return (x == reverse(x));
    }  
    
private:
    long long reverse(int x) {
        long long reverse = 0;

        while (x) {
            reverse = reverse*10 + x%10;
            x /= 10;
        }

        return reverse;
    }
};
