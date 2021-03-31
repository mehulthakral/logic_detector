    int strStr(string haystack, string needle) {

        if(haystack.size() < needle.size())
            return -1;
        
        int index = 0;
        int i,j;
        for(i = 0, j = 0;i < haystack.size() && j < needle.size();){
            if(haystack[i] == needle[j]){
                i++; j++;
            }else{
               index++;
               i = index;
               j = 0;
            }
        }
    
        if(j == needle.size())
            return index;
        return -1;
   }