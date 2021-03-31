class Solution {
public:
    int countPrimes(int n)
    {
        if(n<=1)return 0;
        
        valarray<bool> varr(true,n);
        varr[0]=varr[1]=false;
        
        size_t sqroot=sqrt(n);
        if(2<=sqroot)//special case for 2. so that in loop we dont have to check even numbers.
        {
            varr[std::slice(4,ceil((varr.size()-4)/float(2)),2)]=false;
        }
        for(size_t i{3},sz{varr.size()};i<=sqroot;i+=2)
        {
            if(size_t j{i*i};varr[i])
            {
                varr[std::slice(j,ceil((sz-j)/float(i)),i)]=false;
            }
        }
        return std::accumulate(begin(varr),end(varr),0);
    }
};