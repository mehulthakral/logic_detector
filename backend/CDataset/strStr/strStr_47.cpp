  int strStr(char *haystack, char *needle) {
		 int plen = strlen(needle);
		 int next[26], i, j;
		 for (i = 0; i<26; i++){
			 next[i] = plen + 1;   
		 }
		 for (i = 0; i<plen; i++){
			 next[needle[i] - 'a'] = plen - i; 
		 }
		 char *head = haystack;
		 int result = -1;
		 int times;
		 while (strlen(head) >= plen){
			 if (memcmp(head, needle, plen) == 0)
			 {
				 result = head - haystack;
				 break;
			 }
			 else {
				 times = next[*(head + plen) - 'a'];
				 head += times;
			 }
		 }
		 return result;
    }