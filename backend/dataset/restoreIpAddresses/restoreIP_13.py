class Solution:
    def __init__(self):
        self.result = []

    def restoreIpAddresses(self, s: str) -> List[str]:
        def is_valid(part: str) -> bool:
            part_len = len(part)
            if part_len > 3:
                return False
            if part[0] == '0' and part_len != 1:
                return False
            if int(part) > 255:
                return False
            return True

        def backtrack(string: str, parts=[]):
            if len(parts) == 3:
                if is_valid(string):
                    parts.append(string)
                    self.result.append(str.join('.', parts))
                    parts.pop()
                return
            for dot in range(1, min(len(string), 4)):
                part = string[0:dot]
                rest = string[dot:]
                if is_valid(part):
                    parts.append(part)
                    backtrack(rest, parts)
                    parts.pop()

        backtrack(s, [])
        return self.result        
