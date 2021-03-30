class Solution {
public:
    int Stoi(string s)
    {
        int i,p=0;
        for(i=0;i<s.length();i++)
            p=p*10+(s[i]-48);
        return p;
    }
    void getIpAddress(vector<string> &V,string &s,string res,int c,int i)
    {
        if(c==4)
        {
            string d=s.substr(i,s.length()-i);
            if(d.length()>=4 || d.length()==0 || Stoi(d)>255 || (d.length()!=1 && d[0]=='0'))
                return;
            res+=d;
            V.push_back(res);
            return;
        }
        for(int j=i;j<s.length();j++)
        {
            string d=s.substr(i,j-i+1);
            if(d.length()>=4 || d.length()==0 || Stoi(d)>255 || (d.length()!=1 && d[0]=='0'))
                return;
            int p=d.length()+1;
            res+=d;
            res.push_back('.');
            getIpAddress(V,s,res,c+1,j+1);
            while(p--)
            res.pop_back();
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> V;
        getIpAddress(V,s,"",1,0);
        return V;
    }
};
