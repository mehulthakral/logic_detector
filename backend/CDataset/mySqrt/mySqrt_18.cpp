class Solution {
public:
    int util(int x, int low, int high){
        
        while(low < high){
            int mid = low + (high-low)/2;
            if((long)mid*mid < x){
                low = mid+1;
            }else{
                high = mid;
            } 
        }
        return (long)low*low > x ? low-1 : low;
        
    }
    
    int mySqrt(int x) {
     
        
        return util(x, 1, x/2);
    }
};