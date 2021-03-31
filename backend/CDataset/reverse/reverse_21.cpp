class Solution {
public:
    int reverse(int x) {
        stringstream ss;
        long long int ans;
        ss << x;
        string str;
        ss >> str;
        if(str[0]=='-') for(int i =1 ; i<=str.size()/2 ; i++)swap(str[i], str[str.size() -i]);
        else for(int i =0 ; i<str.size()/2 ; i++)swap(str[i], str[str.size()-1 -i]);
        ss.str("");
        ss.clear();
        ss << str;
        ss >> ans;
        if((abs(ans) >> 31) != 0)return 0;
        return ans;
    }
};
