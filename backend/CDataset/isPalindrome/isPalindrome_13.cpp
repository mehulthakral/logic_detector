class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        vector<int> v;
        while(x){
            v.push_back(x%10);
            x=x/10;
        }
        int i=0,j=v.size()-1;
        while(i<j){
            if(v[i++]!=v[j--]){
                return false;
            }
        }
        return true;
    }
};
