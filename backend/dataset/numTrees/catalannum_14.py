class Solution:
    def numTrees(self, n: int) -> int:
        ans = {}
        ans[0] = 1  ### for the case where left side or right side no elements
        ans[1] = 1
        ans[2] = 2
        
        for i in range(3,n+1):   ###  to find numTrees() for elements before n..so we can use that in our DP
            cnt = 0    
            for j in range(1,i+1):  ###  split element on all possible index from index 1 to index last
                right = i-j      ### number of elements in right
                left = j-1       ### number of elements in left
                
                r_cnt=ans[right]  ###  number of combinations of right side
                l_cnt=ans[left]   ###  number of combinations of left side
                
                cnt += l_cnt*r_cnt  ###  total combination possbile from that tree is left*right
                
            ans[i] = cnt           ### add final ans to DP..so we can use later
            
        return ans[n]
