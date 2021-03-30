    if(x<0) return false;
    if(x>=0 && x<10 ) return true;
    long rv = 0;
    int og = x;
    while(x != 0){
        rv = rv * 10 + (x%10);
        x /= 10;
    }
    if(og == rv){
        return true;
    }
    else{
        return false;
    }
}