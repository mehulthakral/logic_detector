 int mySqrt(int x)
{
    long mid ;  // because we have to do mid*mid 
    if(x ==0 || x==1) return x;
    
    int i=0, j=x ;
    while(i<j)
    {
        mid = (i+j)/2;
        
        if(mid*mid == x)  return mid;
        else if(mid*mid < x) i = mid;
        else j=mid;
        
         if(j-i==1) return i;   
    }
    return i;
}