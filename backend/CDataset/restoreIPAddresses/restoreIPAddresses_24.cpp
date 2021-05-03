class Solution {
public:
    vector<string> result;
    string solution;
    
    vector<string> restoreIpAddresses(string s) {
        //initally our start==0 and part==0 as we haven't start processing.
        backtracking(s, 0, 0);
        return result;
    }
    
private:
    void backtracking(string s, int start, int part)
    {
        
        if(start == s.size() && part == 4)
        {
            result.push_back(solution);
            return;
        }
        //Start trasversing the string till the end of the string.
        for(int i = start; i < s.size(); i++)
        {
            //if we satisfy 3 Conditions, we need to continue else Not.
            /*
            1- if part<4 means if we have a.b. part==2, need more processing. 
            2- (i-start<3): we are just handling max to max 3 characters. like if we have
                1234.5 stop processing.
            3- the string from start to current i. string(start,i)= is valid
            */
            if(part < 4 && i-start < 3 && validIP(s, start, i))
            {
                //append that string to solution.[ its appennd]
                solution.append(s.substr(start, i-start+1));
                //included 1 part so incrementing the part by 1.
                part++;
                //if parts remaining : then we add '.' else we dont need like 123.456.123.2
                if(part < 4) solution.push_back('.');
                //go from i+1 and do the reaming from i+1 till end of the string.
                backtracking(s, i+1, part);
                // if its the last part No need of popping the last character eg: 255.255.111.35, 
                //No need of popping the 35.
                if(part < 4) solution.pop_back();
                
                
                //decrement the parts coz we are trying the next combination.
                // eg: 255.255.11 part was 3, Now we are ready to remove 11, and try for 111 so do
                // parts--.
                part--;
                //remove the part added. 
                for(int j = 0; j < i-start+1; j++) solution.pop_back();
            }
            //else continue;
        }
    }
    
    
    bool validIP(string s, int start, int end)
    {
        //find the substring from start to the end and convert into integer.
        string temp = s.substr(start, end-start+1);
        int ip = stoi(temp);
        
        //if we have ip=012, its invalid but if its ip=0 its valid like 127.0.0.1 :p
        if(s[start] == '0' && start != end) return false;
        //self explanatory
        else if(ip >= 0 && ip <= 255) return true;
        
        //eg: 256
        return false;
    }
};
