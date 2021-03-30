    bool isPalindrome(int x) {
        if(x==0)return true;
        int n=x;
        int sign=(x>0)?1:-1;
        if(sign<0)return false;
        x=abs(x);
        int r=0;
        while(x>0)
        {
            if(r>INT_MAX/10 || r==INT_MAX/10 && x%10>7)return false;
            r=r*10+x%10;
            x/=10;
        }
        return r==n;
    }