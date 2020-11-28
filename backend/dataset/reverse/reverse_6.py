class Solution:
    def reverse(self, x: int) -> int:
        reversed_number_string = ""
        largest_integer_32_bit = pow(2, 31)
        is_negative = False
        if x == 0:
            return 0
        if x < 0:
            x = abs(x)
            is_negative = True
        while x != 0:
            reversed_number_string += str(x % 10)
            x = int(x / 10)
        reversed_number = int(reversed_number_string)
        if reversed_number > largest_integer_32_bit:
            return 0
        if is_negative:
            return reversed_number * -1
        return reversed_number
