def isPalindrome(self, x: int) -> bool:
    if(x<0):
        return ""
    else:
        x1=x
        count=0
        rev=0
        while(x1>0):
            count+=1
            x1//=10
        if(count==1):
            return "true"
        length=count
        count//=2
        if(length%2==0):
            s=x//(10**count)
            s1=x%(10**count)
            while(s>0):
                rev=rev*10+(s%10)
                s=s//10
            if(s1==rev):
                return "true"
        else:
            s=x//(10**(count+1))
            s1=x%(10**count)
            while(s>0):
                rev=rev*10+(s%10)
                s=s//10
            print(rev)
            
            if(s1==rev):
                return "true"