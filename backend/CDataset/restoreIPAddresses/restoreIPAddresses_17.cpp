class Solution {
public:
    void restoreIpAddresses(vector<string> &v, string s, int pos, int dot, string r)
    {
        if(dot==4)
        {
            if((s.length() <= pos) || (s.length() - pos > 3))
                return;
            string sub = s.substr(pos);
            if((sub[0] == '0') && (sub.length() > 1))
            {
                return;
            }
            if(stoi(sub) < 256)
            {
                r += sub;
                v.push_back(r);
            }
            return;
        }
        for(int i=1;i<4;++i)
        {
            if((s.length() <= pos+i))
            {
                return;
            }
            string sub = s.substr(pos, i);
            if((sub[0] == '0') && (sub.length() > 1))
            {
                return;
            }
            if(stoi(sub) < 256)
            {
                r += sub;
                r += ".";
                restoreIpAddresses(v, s, pos+i, dot+1, r);
                r = r.substr(0,r.length()-i-1);
            }
        }
    }
vector<string> restoreIpAddresses(string s) {
    vector<string> ret;
    int len = s.length();
    if(len < 4)
        return ret;
    if(len > 12)
        return ret;

    restoreIpAddresses(ret, s, 0, 1, "");

    return ret;
}
};