class Solution {
public:
    int reverse(int xx) {
      bool neg=false;
        long long int x=xx;
        if(x<0)
        {
            neg=true;
            x*=-1;
        }
        int ans;
        string s=to_string(x);
        std::reverse(s.begin(),s.end());
        try{
            ans=stoi(s); 
        }
        catch(out_of_range& e)
        {
            return 0;
        }
        if(neg)
            ans*=-1;
        return ans;
    }
};
