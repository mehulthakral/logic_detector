class Solution:
    def isPalindrome(self, x) -> bool:
        if x<0:
            return False 
        else:
            x = str(x)
            x = [item for item in x]
            if len(x)%2 ==0:
                part1 = x[0:int(len(x)/2)]
                part2 = x[int(len(x)/2):]
                if part1 == part2[::-1]:
                    return True 
                else:
                    return False 
            else:
                part1 = x[0:int(len(x)/2)]
                part2 = x[int(len(x)/2)+1:]
                if part1 == part2[::-1]:
                    return True 
                else:
                    return False 
