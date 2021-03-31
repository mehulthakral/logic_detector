class Solution {
public:
    bool isPalindrome(int x) {
        bool ans = false;
        if(x<0){
            return ans;
        }
        
        int ch=x,y=0;
        while(x){
            if(INT_MAX/10 < y){return ans;}
            
            y = (y*10)+(x%10);
            x = x/10;
        }
        if(ch==y){
            ans=true;
            return ans;
        }else{
            return ans;
        }
    }
};
