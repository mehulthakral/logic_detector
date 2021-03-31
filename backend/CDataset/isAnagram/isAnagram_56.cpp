class Solution {
public:
bool isAnagram(string s, string t) {

    if(t.size()!=s.size())
    {
        return false;
    }
    if(s==t)
    {
        return true;
    }
    map<char,int>m1;
    map<char,int>m2;
    map<char,int>::iterator it1;
    map<char,int>::iterator it2;
    for(char c:s)
    {

        it1=m1.find(c);
    if(it1==m1.end())
    {
        m1.insert(pair<int,int>(c,1));
    
    }
        else
        {
            it1->second=it1->second+1;
            
        }
    
    }
    
    
    for(char c:t)
    {

        it2=m2.find(c);
    if(it2==m2.end())
    {
        m2.insert(pair<int,int>(c,1));
    
    }
        else
        {
            it2->second=it2->second+1;
            
        }
    
    }
    
    for(it1=m1.begin();it1!=m1.end();it1++)
    {
        it2=m2.find(it1->first);
        if(it2==m2.end())
        {
            m1.clear();
            m2.clear();
            return false;
        }
        else
        {
            if(it2->second!=it1->second)
            {
                m1.clear();
                m2.clear();
                return false;
            }
        }
        
        
    }
    m1.clear();
    m2.clear();
    return true;
    
    
    
}
};