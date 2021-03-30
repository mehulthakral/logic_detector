class Solution {      
public:        
      int reverse(int x) {     
        int res =0,tmp = res;   
        for(;x;tmp = res,res = x%10 + res*10,x = x/10);     
        return tmp!=res/10 ?0:res;    
    }
};