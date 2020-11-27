class Solution:
    def reverse(self, x: int) -> int:
        # initialize variable "result" as a reversed string of the characters
        result = str(x)[::-1]
        # if the number was negative, the last character will be "-"
        # remove the "-" from the end of the string and turn into negative int of the characters
        if result[-1] == "-":
            result = -int(result[:-1])
        # if the number was not negative, turn into an int
        else:
            result = int(result)
        # if the result is larger than a 32-bit int, return 0
        if result > 2**31 or result < -2**31:
            return 0
        return result
