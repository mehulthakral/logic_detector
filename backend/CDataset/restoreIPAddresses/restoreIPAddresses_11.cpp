class Solution {
public:
vector<string> restoreIpAddresses(string s) {
    vector<string> result;
    if(s.size()<4 || s.size() > 12) return result;
    dfs(s, 0, 0, s, result);
    return result;
}

void dfs(string& s, int start, int dot, string path, vector<string>& result){
       // dot : number of dot
    if(dot==3 && stoi(s.substr(start, s.size()-start))<=255 ){
        result.push_back(path);
        return;
    }

    
    for(int i=start; stoi(s.substr(start, i-start+1))<=255 && i<s.size()-1; ++i){
        path.insert(i+1+dot, ".");
        dfs(s, i+1, dot+1, path, result);
        path.erase(i+dot+1,1);
    }
}

int stoi(string s){
    if(s[0]=='0' && s.size()>1) 
        return INT_MAX;
    int nn;
    istringstream(s) >> nn;
    return nn;
}
};