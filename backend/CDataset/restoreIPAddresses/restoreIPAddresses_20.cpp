class Solution 
{
public:
    bool is_valid(string s)
    {
        if(s.length()>3)
        {
            return false;
        }
        if(s[0]=='0' && s.length()>1)
        {
            return false;
        }
        return stoll(s)>=0 && stoll(s)<=255;  
    }
    vector<string> restoreIpAddresses(string s)
    {
        vector<string>v;
        for(int i=1;i<=3 && s.length();i++)
        {
            string first=s.substr(0,i);
            if(is_valid(first))
            {
                for(int j=1;j<=3 && i+j<s.length();j++)
                {
                    string second=s.substr(i,j);
                    if(is_valid(second))
                    {
                        for(int k=1;k<=3 && i+j+k<s.length();k++)
                        {
                            string third=s.substr(i+j,k);
                            string fourth=s.substr(i+j+k);
                            if(is_valid(third) && is_valid(fourth))
                            {
                                v.push_back(first+"."+second+"."+third+"."+fourth);
                            }
                        }
                    }
                }
            }
        }
        return v;
    }
};
