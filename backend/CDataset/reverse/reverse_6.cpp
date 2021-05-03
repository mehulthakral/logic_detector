class Solution {
public:
    int reverse(int x) {
        
         int t = abs(x);
         int sum =0;
         int restraint  = pow(2,31)-1;
         int res;
        
         while(t>0){
            
            if(sum<=restraint/10){
                sum = sum*10+t%10;
                t = t/10;
            }else{
                return 0;
            }
            
        }
        res = x>=0?sum:-sum;   
        return res; 
       
         
    }
};
