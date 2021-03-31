 bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;
        
		// Sort strings
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
		/* 
			If the two strings don't match at every index 
			then the strings are not anagrams of each other
		*/
        for (int i=0; i < s.length(); i++)
        {
            if (s[i] != t[i])
                return false;
        }
        
        return true;
    }