class Solution {
public:
    int reverse(int x) {
      
        int z = 0;
      
        while(x){
        
            if(z>INT_MAX/10 || z==INT_MAX/10 && x%10>7)
                return 0;
            if(z<INT_MIN/10 || z==INT_MIN/10&&x%10<-8)
                return 0;
         
            z = z *10 +x%10;x = x/10;
        }
        
        return z;
    }
};
