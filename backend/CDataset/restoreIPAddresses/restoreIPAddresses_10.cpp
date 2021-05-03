class Solution {
public:
void restoreIpAddressesHelper(string& s, int dotNum, int idx, string str, string lastVal,
                              vector<string>& res) {
  if (dotNum > 3 || idx > s.size() || atoi(lastVal.c_str()) > 255 || lastVal.size() > 3) return;
  if (dotNum == 3 && idx == s.size() && str.back() != '.')
    res.push_back(str);
  if (str.back() == '.') {
    restoreIpAddressesHelper(s, dotNum, idx + 1, str + s[idx], string(1, s[idx]), res);
  } else {
    restoreIpAddressesHelper(s, dotNum + 1, idx, str + '.', string(""), res);
    if (lastVal[0] != '0')
      restoreIpAddressesHelper(s, dotNum, idx + 1, str + s[idx], lastVal + s[idx], res);
  }
}
vector<string> restoreIpAddresses(string s) {
  vector<string> res;
  if (s.size() < 4) return res;
  restoreIpAddressesHelper(s, 0, 1, string(1, s[0]), string(1, s[0]), res);
  return res;
}
};