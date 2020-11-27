class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        ans=[]

        def recur(start_index,prev_string,count):
            if count>4:
                return
            # print(prev_string)
            if (start_index==len(s)):
                if count<4:
                    return
                ans.append(prev_string[:-1])
                # print(prev_string[:-1])

            else:
                for i in range(start_index,start_index+3):
                    if (i<len(s)):
                        to_attach=s[start_index:i+1]

                        # print(to_attach)
                        if to_attach[0]=="0":
                            if len(to_attach)==1:
                                # print("here")
                                recur(i+1,prev_string+to_attach+".",count+1)
                            else:
                                continue
                        elif int(to_attach)<=255:
                            recur(i+1,prev_string+to_attach+".",count+1)






        recur(0,"",0)
        return ans
