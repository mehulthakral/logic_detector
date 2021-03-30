class Solution {
    vector<string> vec,ans;
public:
    bool isvalid(string t){
        if(t[0]=='0' && t.size()>1) return false;
        int a=stoi(t);
        return a>=0 && a<=255;
    }
    string conv(vector<string> &st){
        string tem="";
        for(int i=0;i<st.size()-1;i++){
            tem+=(st[i]+".");
        }
        tem+=st[st.size()-1];
        return tem;
    }
    void fun(int ind,int c,string te){
        if(c==0 && ind==te.size()){
            ans.push_back(conv(vec));
            return;
        }
        if(c==1){
            if((te.size()-ind)>3){
                return;
            }
        }
        string tem;
        for(int i=ind;i<te.size() && (i-ind+1)<=3;i++){
            tem.push_back(te[i]);
            if(isvalid(tem)){
                vec.push_back(tem);
                fun(i+1,c-1,te);
                vec.pop_back();
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        fun(0,4,s);
        return ans;
    }
};
