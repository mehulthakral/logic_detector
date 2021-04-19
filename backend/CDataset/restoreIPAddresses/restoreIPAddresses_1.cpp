class Solution {
public:
    #include<vector>
    bool isValid(string s){
        int num = stoi(s);
        if(num > 255)
            return false;
        return s.size() == to_string(num).size();
    }
    string getIPAddress(vector<string> &parts){
        string ans = "";
        for(int i = 0; i < parts.size(); i++){
            ans += parts[i];
            if(i < parts.size() - 1)
                ans += '.';
        }
        return ans;
    }
    vector<string> restoreIpAddresses(string s) {
        if(s.size() > 12)
            return vector<string>{};
        vector<string> ans;
        for(int i = 1; i < min((int)s.size(), 4); i++){
            vector<string> parts = {"","" ,"" ,"" };
            parts[0] = s.substr(0, i);
            if(isValid(parts[0])){
                for(int j = i + 1; j < min((int)s.size(), i + 4); j++){
                    parts[1] = s.substr(i, j - i);
                    if(isValid(parts[1])){
                        for(int k = j + 1; k < min((int)s.size(), j + 4); k++){
                            parts[2] = s.substr(j, k - j);
                            parts[3] = s.substr(k);
                            if(isValid(parts[2]) && isValid(parts[3])){
                                ans.push_back(getIPAddress(parts));
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};
