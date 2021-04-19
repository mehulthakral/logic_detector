class Solution {
public:
    int countPrimes(int n)
    {
        if(n<=1)return 0;
        vector<bool> V(n,true);
        for(size_t i{2},s=sqrt(n);i<=s;++i)
        {
            if(V[i])
            {
                for(size_t jump{i*i};jump<V.size();jump+=i)
                    V[jump]=false;
            }
        }
        return std::accumulate(V.cbegin()+2,V.cend(),0);
    }
};