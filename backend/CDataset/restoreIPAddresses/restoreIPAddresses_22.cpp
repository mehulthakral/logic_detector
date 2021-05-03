class Solution {
public:
    int toInt(string s) {
        int i=0, ans=0;
        while(s[i]!='\0') {
            ans*=10;
            ans+=s[i]-'0';
            i++;
        }
        return ans;
    }
    
    void solve(string s, vector<string>& ans, string str, int count) {        
        if(count==4) {
            if(s.size()==0) {
                str.erase(str.size()-1);
                ans.push_back(str);
            }
            return;
        }
        if(s.size()==0)
            return;
        
        for(int i=0; i<3; i++) {
            if(i>=s.size())
                break;
            string temp= s.substr(0, i+1);
            int k= toInt(temp);
            
            if((k==0 && i==0) || (k<256 && temp[0]!='0')) {
                string right= s.substr(i+1);
                solve(right, ans, str+temp+".", count+1);
            }
            else break;
        }
    }
    
    
    vector<string> restoreIpAddresses(string s) {
        
        vector<string> ans;
        
        if(s.length()<4 || s.length()>12)
            return ans;
        
        solve(s, ans, "", 0);
        return ans;
    }
};