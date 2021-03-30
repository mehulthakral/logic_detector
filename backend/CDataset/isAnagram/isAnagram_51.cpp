bool isAnagram(string s, string t) {
        vector<int> vec1(26, 0);
        int i;
        for(i=0; i<s.size(); i++)
            vec1[s[i]-'a']++;
       
        for(i=0; i<t.size(); i++)
        {
            if(vec1[t[i]-'a'] ==0)
                return false;
            vec1[t[i]-'a']--;
        }
        return true;
    }