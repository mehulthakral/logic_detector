class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<vector<string>> cur(4), prev(4);
        cur[0].push_back(s.substr(0, 1));
        for (int i = 1; i < s.size(); ++i) {
            swap(cur, prev);
            for (int p = 0; p < 4; ++p) {
                cur[p].clear();
                if (p > 0) {
                    for (auto& str : prev[p - 1]) {
                        cur[p].push_back(str + "." + s[i]);
                    }
                }
                for (auto str : prev[p]) {
                    str += s[i];
                    auto pos = str.rfind('.');
                    int last = stoi(str.substr(pos + 1));
                    if (str[pos + 1] != '0' && last <= 255)
                        cur[p].push_back(str);
                }                
            }
        }
        return cur[3];
    }
};