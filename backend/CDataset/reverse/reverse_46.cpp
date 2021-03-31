    long int res=0;
    int i;

    while(x){
        res = res*10+x%10;
        x = x/10;
    }
    if(abs(res)>pow(2,31))
        return 0;
    return res;