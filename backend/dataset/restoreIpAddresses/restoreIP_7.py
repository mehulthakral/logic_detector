class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        ## RC ##
        ## APPROACH : BACKTRACKING ##
        ## EDGE CASE : zeros 00 ## ( case : "010010")
		
        ## TIME COMPLEXICITY : O(1) ##
		## SPACE COMPLEXICITY : O(1) ##
        
        """
        one already put a dot that leaves only 3 possibilities for the next dot to be placed : after one digit, after two digits, or after three digits. The first dot has only 3 available slots as well.
        it's enough to check just 3×3×3=27. ==> O(1)
        """
	
        def backtrack( curr, s, k ):
            if( k < 0 ):
                return
            
            if(not s and k == 0):
                self.res.append(".".join(curr[:]))
                return
            
            if( len(s) > 3 * (4 - len(curr)) ):             # optimization early pruning, when we have too many dgitis for next slots
                return
            
            num = 0
            for i in range(min(3,len(s))):                  # max size 3
                num = num * 10 + int(s[i])
                if( i > 0 and s[0] == "0" or num > 255 ):   # edge case, when we are filling a slot starting 0, donot consider later numbers
                    break                                   # break, (not continue)
                if( 0 <= num <= 255 ):
                    backtrack( curr+[str(num)], s[i+1:], k-1 )
        
        self.res = []
        backtrack( [], s, 4 )
        return self.res
