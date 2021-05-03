class Solution {
public:
int reverse(int x) {
        int p=x>0?x:-x;     
             // p is the abs value
        long int result=0;
             // in case of overflow, we choose long int
        while(p!=0){
            result=result*10+p%10;
            p/=10;
        }
             //reverse the abs value
        result=(x>0)?result:-result;
             //check if x>0
        if(result>INT_MAX||result<INT_MIN)
            return 0;
             //check overflow
        return result;
    }
};