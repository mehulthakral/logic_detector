class Solution {
public:
    vector<string> res= vector<string>();
    void ip(string &s,int k,int slot,int n,string ans)
    {
        if(slot>5)
            return;
        if(ans.length()==n+3)
        {
            res.push_back(ans);
            return;
        }  
        string temp="";
        if(slot!=1)
            ans+="."; 
        for(int i=k;i<(n-k>3?k+3:n);i++)
        {
            temp+=s[i];
            if(s[i]=='0' && i==k)
            {
                ip(s,i+1,slot+1,n,ans+temp);
                return;
            }
            // now check the no is less than 255 and tthe remaning element should be between min and max ranges of slot (here slot means total value in befor .) 
            if( stoi(temp)<=255 && n-i-1<=(4-slot)*3 && n-i-1>=4-slot)           
                ip(s,i+1,slot+1,n,ans+temp);   
        }
    }
    vector<string> restoreIpAddresses(string s) {
        int n=s.length();
        if(n<=12)
        ip(s,0,1,n,"");
        return res;
    }
};
