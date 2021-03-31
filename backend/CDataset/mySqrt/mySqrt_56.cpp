struct precalc {
    static constexpr int max_root = 46341;        
    constexpr precalc() : v() {    for (int i = 0; i < max_root; ++i) v[i] = i*i;    }
    int v[max_root];
};

class Solution 
{
    static constexpr precalc val {};
public:
    int mySqrt(int x) 
    {
        const auto first_it = cbegin(val.v);
        const auto last_it = cend(val.v);        
        auto res_it = lower_bound(first_it, last_it, x);
        if(res_it != last_it && *res_it == x) return res_it - first_it;
        return res_it - first_it - 1;
    }
};

