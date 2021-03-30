class Solution {
public:
    vector<string> ans;
    bool isValid(string s){
        if(s[0]=='0' && s.size()>1) return false;
        int num=stoi(s);
        return num>=0 && num<=255;
    }
    
    void helper(string sans,int count,string s){
        if(count>4) return;
        if(count==4 && s.size()==0){
            sans.pop_back();
            ans.push_back(sans);
            return;
        }
        else if(count==4 || s.size()==0) return;
        
        for(int i=1;i<=3 && i<=s.size();i++){
            string snap=s.substr(0,i);
            if(isValid(snap)){
                helper(sans+snap+".",count+1,s.substr(i));
            }
            else{
                continue;
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        string sans="";
        helper(sans,0,s);
        return ans;
    }
};

