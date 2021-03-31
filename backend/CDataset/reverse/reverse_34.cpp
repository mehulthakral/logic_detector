class Solution {
public:
    int reverse(int x) {
        //check if the first part overflows
        if (x > INT_MAX || x < INT_MIN) return 0;
        
        int reverse = 0;
        
        while(x != 0) {     
            //these conditions check if reverse will be larger than INT_MAX or smaller than INT_MIN by a factor of 10.
            //the 7 and -8 are represent the last digit of INT_MAX and INT_MIN.
            //Their condition explains that as long as the remainder is from 0 to 7, or -8 to 0 inclusive,
            //the x value can be from 0 to INT_MAX, or INT_MIN to 0 range.
            if ((reverse > INT_MAX/10 || reverse < INT_MIN/10) && ((x > 0 && (x % 10 <= 7)) || x < 0 && (x % 10 >= -8))) return 0;
            
            //change reverse value
            reverse = reverse * 10 + x % 10;
            
            //to get next values, divide x by ten
            x /= 10;
        }
        
        return reverse;
    }
};
