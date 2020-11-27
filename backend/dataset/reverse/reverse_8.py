class Solution:
    def reverse(self, x: int) -> int:
        output = ''
        str_x = str(x)
        if str_x[0] == '-':
            output+='-'
            for i in range(len(str_x)-1,0,-1):
                output+=str_x[i]
        else:
            for j in range(len(str_x)-1,-1,-1):
                output+=str_x[j]
        if int(output) not in range(-2147483648,2147483648):
            return 0
        return int(output)
