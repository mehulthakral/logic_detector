class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        int length = s.size();
        vector<string> rt;
        
        backtracking(rt, s, 0, 1);
        return rt;
    }
    
    // level indicates how many '.'s inserted
    void backtracking(vector<string> &rt, string& s, int index, int level){
        if(level == 4){
            if(s.size()-index <= 3 && s.size()-index > 0 && check(s))
                rt.push_back(s);
            return;
        }
        
        for(int i=index+1; i<=index+3 && i<s.size(); i++){
            s.insert(i, ".");
            backtracking(rt, s, i+1, level+1);
            s.erase(i, 1);
        }
    }
    
    bool check(string s){       // check if the string is valid or not
        int left = 0, right = 0;
        while(right < s.size()){
            left = right; right++;
            while(right < s.size() && s[right++] !='.')

            if(right - left == 2 && s[left] == '0') return false;
            else if(right - left == 3){
                if(s[left] == '0') return false;
                if(s[left] > '2') return false;
                if(s[left] == '2' && s[left+1] > '5') return false;
                if(s[left] == '2' && s[left+1] == '5' && s[right-1] > '5') return false;
            }
        }
        return true;
    }
};
