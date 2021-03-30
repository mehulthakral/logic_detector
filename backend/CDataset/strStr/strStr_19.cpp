class Solution {
public:
    int strStr(string haystack, string needle) {
        // Base cases
        auto n = haystack.length(); auto m = needle.length();
        if (m == 0) return 0;
        if (n == 0 || n < m) return -1;
 
        // Hashing:
        // or using fast integer power algo: 
        // radix^(m - 1) % prime: int h = pow(d, m - 1) % q;                                            
        int d = 31;                                                     // radix - beneficial to make smaller      
        int q = 15486703;                                               // some big prime
        long p = 0; long t = 0; long h = 1;
       
        for (auto i = 0; i < m; ++i) {                                  // preprocessing hashes for pattern and text
            if (i != m - 1) 
                h = (d * h) % q;
            p = (d * p + needle[i]) % q;
            t = (d * t + haystack[i]) % q;
        }
        
        for (auto s = 0; s < n - m + 1; ++s) {
            if (t < 0) t += q;                                           // fix negative hash
            if (p == t)                                                  // hash matched
                if (needle == haystack.substr(s, m))                     // collision handling
                    return s;
            if (s < n - m)                                               // updating hash: pop front char, push new
                t = (d * (t - haystack[s] * h) + haystack[s + m]) % q;
        }
        
        return -1;   
    }
};

