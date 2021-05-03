class Solution {
public:
vector<string> restoreIpAddresses(string s) {
        if (s.empty()) return {};
        vector<string> res;
        dfs("", 1, 0, res, s);
        return res;
    }

    void dfs(string prefix, int step, int start, vector<string> &res, string &str) {
        //step mean next find segment step, prefix is 4 more dots than str.size()
        if (step == 5 && prefix.size() - str.size() == 4) {
            prefix.pop_back();
            res.push_back(prefix);
            return;
        }
        if (step > 5) {
            return;
        }
        for(int i = 1; i < 4; i++) {
            int end = start + i;
			//handle '001' case
            if(end > str.size() || (i > 1 && str[start] == '0')) continue;
            string segment = str.substr(start, i);
            int num = stoi(segment);
            if(num < 0 || num > 255) {
                continue;
            }
            dfs(prefix + segment + ".", step+1, end, res, str);
        }
    }
};