  vector<string> restoreIpAddresses(string s) {
    std::vector<std::string> ret;
    char temp[15 + 1] = {0};
    
    // Recursive function that progressively cycles through valid numbers lengths 
    std::function <void (const char* pos, int len, char* buf, int count)> helper;
    helper = [&ret, &temp, &helper] (const char* pos, int len, char* buf, int count) -> void {
      // Check if there is the right amount of input string left
      if (len >= (4 - count) && len <= (4 - count) * 3) {
        if (4 == count)
        {
          ret.push_back(temp);
        } else {
          // '0' is a special case. '0' is valid number, "00" is not. Only recurse on a single digit
          int sub_len = ('0' == *pos) ? 1 : std::min(3, len);

          // Recurse around, using upto 3 digits for the number, then 2, then 1
          buf += sprintf(buf, "%s%.*s", ((count) ? "." : ""), sub_len, pos);
          switch (sub_len) {
            default: 
              if (0 < memcmp("256", pos, 3)) {
                helper(pos + 3, len - 3, buf, count + 1);
              }
              --buf;  // Fall-through*/
            case 2: helper(pos + 2, len - 2, buf--, count + 1); // Fall-through
            case 1: helper(pos + 1, len - 1, buf--, count + 1);
          }
        }
      }
    };
    
    helper(s.c_str(), s.size(), temp, 0);
    return ret;
  }