class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        if(s.length()!=t.length())
        {
            return false;
        }
        unordered_map<char, int>mp1,mp2;
        unordered_map<char, int>::iterator itr1,itr2;
        for(int i=0;i<s.length();i++)
        {
            mp1[s[i]]++;mp2[t[i]]++;
        }
        for(itr1=mp1.begin(),itr2=mp2.begin();itr1!=mp1.end();itr1++,itr2++)
        {
            itr2=mp2.find(itr1->first);
            if(itr2!=mp2.end())
            {
                if(itr2->second!=itr1->second)
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
