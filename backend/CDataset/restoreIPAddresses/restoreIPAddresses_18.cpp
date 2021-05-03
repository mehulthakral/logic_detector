class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        int n = s.size();
        vector<string> result;
        vector<long> maxVals = {255255255255, 255255255, 255255, 255};
        string curIp = "";
        helper(s, 0, maxVals, result, curIp);
        return result;
    }
    
    void helper(string& s, int dec, vector<long>& maxVals, vector<string>& result, string& curIp) {
        int n = s.size();
        long int curNum = strtol(s.c_str(),NULL,10);
        if (n < 4-dec ||  curNum > maxVals[dec]) {
            return;
        }
        
        if (dec == 3) {
            if (n == 1 || curNum >= pow(10,n-1)) {
                curIp += s;
                result.push_back(curIp);
            }
            return;
        }
        dec++;
        int i = 1;
        while(i <= 3 && i < n) {
            string cur = string(s,0,i);
            long int num = strtol(cur.c_str(), NULL, 10);
            // cases like 010010, basically neglect the ones starting with 0 if i > 1
            if (num > 255 || (i > 1 && num < pow(10,i-1))) {
                i++;
                continue;
            }
            string nextIp = curIp + cur + ".";
            string rem = string(s, i, n-i);
            helper(rem, dec, maxVals, result, nextIp);
            i++;
        }
    }
};