class Solution:
    def restoreIpAddresses(self, s: str):
        ret = []
        self.dfs(ret, s, [])
        return ret

    def dfs(self, ret, s, path_list):
        if len(path_list) == 4:
            if s == '':
                ret.append('.'.join(path_list))
            return
        if not s:
            return
        if s[0] == '0':
            temp_path_list = path_list[::]
            temp_path_list.append('0')
            self.dfs(ret, s[1:], temp_path_list)
            return
        for i in range(len(s)):
            if i >= 3:
                break
            if int(s[:i + 1]) <= 255:
                temp_path_list = path_list[::]
                temp_path_list.append(s[:i + 1])
                self.dfs(ret, s[i + 1:], temp_path_list)
