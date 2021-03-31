class Solution {
public:
    int reverse(int x) {
        string str;
        stack<char> integers;
        if (x < 0)
            str += "-";
        
        string input = to_string(abs(x));
        for (char const &c: input) 
            integers.push(c);
        
        while (!integers.empty()) {
            str += integers.top();
            integers.pop();
        }
        
        if (abs(stol(str)) > INT_MAX)
            return 0;
        
        return stoi(str);
    }
};
