bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;
			
        // Arrays used to keep track of character frequency using ASCII values
        char string1[128]{0};
        char string2[128]{0};
        
		// Count number of times a character appears
        for (int i=0; i < s.length(); i++)
        {
            string1[s[i]]++;
            string2[t[i]]++;
        }
        
		/* 
			If the two arrays don't match at every indice then
			the two strings are not anagrams of each other 
		*/
		int len = sizeof(string1)/sizeof(string1[0]);
        for (int i=0; i < len; i++)
        {
            if (string1[i] != string2[i])
                return false;
        }
        
        return true;
    }