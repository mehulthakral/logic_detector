class Solution {
public:
  vector<string> restoreIpAddresses(string s) {
    std::vector<std::string> ret;
    int len[4];
    int offs[4] = {0};
   
    for (len[0] = 1; len[0] <= 3; ++len[0]) {
      for (len[1] = 1; len[1] <= 3; ++len[1]) {
        for (len[2] = 1; len[2] <= 3; ++len[2]) {
          std::partial_sum(std::begin(len), std::end(len) - 1, std::begin(offs) + 1);
          if (offs[3] >= s.size() - 3 && 1 <= (len[3] = s.size() - offs[3]) && 
            all_of(begin(offs), end(offs), [l_it = begin(len), &s] (int off) mutable { 
              return (1 == *l_it || '0' != s[off]) && (3 != *l_it++ || 0 < memcmp("256", &s[off], 3)); 
            }))
          {
            ret.emplace_back(s.substr(0, len[0]) + "." + s.substr(offs[1], len[1]) + "." + s.substr(offs[2], len[2]) + "." + s.substr(offs[3]));
          }
        }
      }
    }
  
    return ret;
  }
};