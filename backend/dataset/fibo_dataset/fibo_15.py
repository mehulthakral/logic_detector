class Solution:
    def fib(self, n: int) -> int:
		# initializing table with hard-coded base values
        table = [0,1,1]

        if n > 2:  # series until 2 is already in table, we needn't calculate again
			# we iterate until the nth term is reached (added an offset of 2 since first two are already in table)
            for i in range(n-2): 
                table.append(table[-1] + table[-2])
        
		# return required nth term,
		# table[-1] would have worked except for n < 2, since our table is initialized until 2nd term.
        return table[n] 
