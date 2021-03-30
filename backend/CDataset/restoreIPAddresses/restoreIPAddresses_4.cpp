class Solution {
public:
    void decomposeIpAddresses(string s, vector<string>&snippets, vector<string>&ipAddresses, int buildPointer){

        // goal or base case
        if(buildPointer == s.size() && snippets.size() == 4){
            cout<<"a"<<endl;
            ipAddresses.push_back(snippets[0] + '.'+ snippets[1] + '.' + snippets[2] + '.' + snippets[3]);
            return ;
        }
        else if(buildPointer == s.size() || snippets.size() == 4){
            return ;
        }


        for(int len = 1; len <= 3 && buildPointer + len <= s.size(); len++){
            // choice
            string snippet = s.substr(buildPointer, len);

            // constraint
            if( (stoi(snippet) > 255) || (snippet.size() > 1 && snippet[0] == '0') )break;

            // Choose , explore , Unchoose
            snippets.push_back(snippet);
            decomposeIpAddresses(s, snippets, ipAddresses, buildPointer+len);
            snippets.pop_back();
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string>ipAddresses;
        vector<string>snippets;
        decomposeIpAddresses(s, snippets, ipAddresses, 0);
        return ipAddresses;
    }
};
