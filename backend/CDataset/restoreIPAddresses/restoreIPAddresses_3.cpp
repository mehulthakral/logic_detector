class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> rt;
        string prev;
        helper(rt, s, prev, 0, 0);
        return rt;
    }
    
    void helper(vector<string>& rt, string& s, string& prev, int index, int periods) {
        //if last num is valid add prev+last num to rt
        if (periods==3 && isValid(s, index, s.length()-1)) {
            prev+='.'+s.substr(index, s.length()-index);
            rt.push_back(prev);
            reduceString(prev, s.length()-index+1);
            return;
        }

        //if too many numbers to make an ip
        if ((4-periods)*3<s.length()-index) return;
                         
        if (index==s.length()) return;
                         
        //tests 3 different sizes(1,2,3) of input for current num
        if (periods!=0) prev+='.';
        for (int i=1; i<=3; ++i) {
            if (isValid(s, index, index+i-1)) {
                prev+=s.substr(index, i);
                helper(rt, s, prev, index+i, periods+1);
                reduceString(prev, i);
            }
        }
        //if there is left over period
        if (prev.length()!=0 && prev[prev.length()-1]=='.') prev.pop_back();
    }
    
    bool isValid(string& s, int start, int end) {
        if (end>=s.length() || start>=s.length()) return false; 
        
        //if string has 4 digits
        if (end-start>2) return false;
        
        //if string starts with 0 and is not the number 0
        if (s[start]=='0' && start!=end) return false;
        
        //calculates the int value for substr start->end
        int sum=0;
        for (int i=0; i<=end-start; ++i) {
            sum+=(s[end-i]-'0')*pow(10, i);
        }
        
        return sum<=255;
    }
                         
    void reduceString(string& s, int n) {
        //if we need to remove more than all just set to empty string
        if (n>=s.length()) {
            s="";
            return;
        }
        
        //removes n elements off the back
        for (int i=0; i<n; ++i) {
            s.pop_back();
        }
        return;
    }
};
