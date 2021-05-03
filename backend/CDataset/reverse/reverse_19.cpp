class Solution {
public:
    int reverse(int num) {
        if(num == -2147483648) return 0;
        
        int rev = 0;
	    bool isNeg = false;
	   
	    if(num < 0) {
	        isNeg = true;
	        num = num * -1;
	    }
	    
        while(num >= 10) {
            rev = rev * 10 + num % 10;
            num = num / 10;
        }
        
		// Checking for overflow when adding the last digit
        // 2147483647 / 10 = 214748364
        if(rev > 214748364) return 0;
            
        if(rev >= 214748364 && num > 7) return 0;
        
        rev = rev * 10 + num % 10;
        
        if(isNeg) {
            rev = rev * -1;
        }
            
        return  rev;
    }
};
