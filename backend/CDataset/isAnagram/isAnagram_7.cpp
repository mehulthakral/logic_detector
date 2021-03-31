class Solution {
public:
    bool isAnagram(string s, string t) {
        int n=s.size();//length of string s
        int n1=t.size();//length of string t
        if(n!=n1){//if length of string is not same
            return false;
        }
        sort(s.begin(),s.end());//use sorting for s
        sort(t.begin(),t.end());//use sorting t
        if(s==t){//if both string is equal then return true
            return true;
        }
        return false;
            
    }
};
