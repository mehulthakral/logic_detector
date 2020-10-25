class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        
        # convert strings to lists
        s_list = []
        t_list = []
        
        for item in s:
            s_list.append(item)
            
        for item in t:
            t_list.append(item)
            
        # loop through items in list
        for item in s_list:
            
            # if it is in the other list, remove that item
            if item in t_list:
                
                t_list.remove(item)

            # if it is not in the other list, then return false
            else:
                return False
            
        # if the other list is empty
        if not t_list:

            return True