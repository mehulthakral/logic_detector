class Solution {
public:
    int reverse(int x) {
        int tut = x;
        if(x >= INT_MAX || x <= INT_MIN){
            return 0;
        }
		//makes positive
        if(x<0){
            tut = -tut;
        }
        string s = to_string(tut);
        ::reverse(s.begin(),s.end());
		//add '-' later
        if(x<0){
            s.insert(s.begin(),'-');
        }
        try{
            x = stoi(s);
        }
        catch(const std::out_of_range& e){
            return 0;
        }
        return x;
    }
};
