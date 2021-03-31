int reverse(int x) {
        int res=0,flag=-1;
        if(x==INT_MIN) 
            return 0;
	// flag for marking -ve numbers.	
        if(x<0){
            flag=1;
            x=abs(x);
        }
        while(x>0){		
		//condition check for overflow.		
            if(res>INT_MAX/10) 
                return 0;
            res=res*10+x%10;
            x/=10;
            
        }
        if(flag==1)
            res=-1*res;
        return res;
    }
