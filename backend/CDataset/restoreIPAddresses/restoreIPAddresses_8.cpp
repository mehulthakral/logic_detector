class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        int len = s.length();
        vector<string> ret;
        string temp;
        
        if (len <= 0 || len > 12)
            return ret;
        
        restore_help(s, ret, temp, 0, 0, len);
        
        return ret;
    }
    void restore_help(string &s, vector<string> &ret, string temp, int step, int start, int len)
    {
        if (step == 4 && start == len)
        {   
            temp.erase(temp.end()-1);
            ret.push_back(temp);
            return;
        }
        if (step == 4 && start <= len)
            return;
        if (step < 4 && start >= len)
            return;
            
        for (int j = 1; (start + j - 1) < len && j <= 3; j++)
        {
            string ss = s.substr(start, j);
                
            if (j > 1 && ss[0] == '0')
                continue;
                    
            if (j == 3)
            {
                int num = (ss[0] - '0') * 100 + (ss[1] - '0') * 10 + (ss[2] - '0');
                if (num > 255)
                    continue;
            }
                
            ss += ".";
            int l = temp.length();
            temp += ss;

            restore_help(s, ret, temp, step+1, start+j, len);
                
            temp.erase(l, ss.length() + 1);
        }
    }
};