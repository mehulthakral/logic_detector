class Solution {
public:
bool isPalindrome(int x) {

    if (x < 0) {
        return false;
    }
    
    if (x == 0) {
        return true;
    }
    
    int x_0 = x;
    long y = 0;
    
    while (x != 0) {
        y = y * 10 + x % 10;
        x /= 10;
    }
    
    if (y == x_0) {
        return true;
    }
    else {
        return false;
    }
    
    // limitation: y must be in the range of - 2147483648 and y > 2147483647
}
};