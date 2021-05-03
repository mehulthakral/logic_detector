class Solution {
public:
vector<string> restoreIpAddresses(string s) {
    vector<string>res;
    if(s.size()<4)
        return res;
    helper(s,0,res,"",0);
    return res;
}
void helper(string s,int idx,vector<string>&res,string curSol,int point){
    if(point>=4){
        if(idx==s.size())
            res.push_back(curSol);
        return;
    }
    if(idx>=s.size())//illegal index
        return;
    int restLen=s.size()-idx;
    for(int i=1;i<=restLen&&i<=3;i++)
    {
        string str=s.substr(idx,i);
        if(validate(str))
        {
            string newSol=curSol;
            if(newSol=="")
                newSol+=str;
            else
                newSol=newSol+"."+str;
            helper(s,idx+i,res,newSol,point+1);
        }
    }
}
bool validate(string s)
{
    if(s.size()>1&&s[0]=='0')
        return false;
    int res=0;
    for(int i=0;i<s.size();i++)
    {
        res=res*10+(s[i]-'0');
    }
    return res>=0&&res<=255;
}};