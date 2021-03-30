class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res, ips;
        findIp(s, 0, ips, res);
        return res;
    }
    
    void findIp(string &s, int index, vector<string> &ips, vector<string> &res) {
        if (ips.size() == 4) {
            if (index == s.size()) {
                string ipAddr = ips[0];
                for (int i = 1; i < 4; ++i) {
                    ipAddr += "." + ips[i];
                }
                res.push_back(ipAddr);
            }
            return;
        }
        string curNum;
        for (int i = index; i < s.size() && i < index + 3; ++i) {
            curNum.push_back(s[i]);
            if (isValidNum(curNum)) {
                ips.push_back(curNum);
                findIp(s, i + 1, ips, res);
                ips.pop_back();
            }
        }
    }
    
    bool isValidNum(string s) {
        if (s.empty() || s.size() > 3) { return false; }
        if (s[0] == '0' && s.size() != 1) { return false; }
        if (s.size() == 3 && stoi(s) > 255) { return false; }
        return true;
    }
};