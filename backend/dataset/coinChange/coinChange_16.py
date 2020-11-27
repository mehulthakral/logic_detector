class Solution:
    def coinChange(self, coins: List[int], amt: int) -> int:
        if not amt:
                return 0
            coins.sort()
            if not coins:
                return -1
            q={0}
            stp=1
            while q:
                nwq=set()
                for a in q:
                    for c in coins:
                        if a+c>amt:
                            continue
                        if a+c==amt:
                            return stp
                        nwq.add(c+a)
            
                stp+=1
                q=nwq
            return -1                
